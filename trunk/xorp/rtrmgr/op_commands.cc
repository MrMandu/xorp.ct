// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2005 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/rtrmgr/op_commands.cc,v 1.52 2005/07/27 23:52:20 pavlin Exp $"

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_GLOB_H
#include <glob.h>
#elif defined(HOST_OS_WINDOWS)
#include "glob_win32.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_SYS_SIGNAL_H
#include <sys/signal.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "rtrmgr_module.h"

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/run_command.hh"

#include "cli.hh"
#include "op_commands.hh"
#include "slave_conf_tree.hh"
#include "template_tree.hh"
#include "slave_module_manager.hh"
#include "util.hh"
#include "y.opcmd_tab.h"

#ifdef HOST_OS_WINDOWS
#define	stat	_stat
#define	S_IFDIR	_S_IFDIR
#define	S_ISREG	_S_ISREG
#endif

extern int init_opcmd_parser(const char *filename, OpCommandList *o);
extern void parse_opcmd() throw (ParseError);
extern int opcmderror(const char *s);

OpInstance::OpInstance(EventLoop&			eventloop,
		       OpCommand&			op_command,
		       const string&			executable_filename,
		       const string&			command_arguments,
		       RouterCLI::OpModePrintCallback	print_cb,
		       RouterCLI::OpModeDoneCallback	done_cb)
    : _eventloop(eventloop),
      _op_command(op_command),
      _executable_filename(executable_filename),
      _command_arguments(command_arguments),
      _run_command(NULL),
      _print_cb(print_cb),
      _done_cb(done_cb)
{
    string errmsg;
    bool success = true;

    XLOG_ASSERT(_op_command.is_executable());

    _op_command.add_instance(this);

    do {
	if (_executable_filename.empty()) {
	    errmsg = c_format("Empty program filename");
	    success = false;
	    break;
	}

	string program_request = _executable_filename;
	if (! _command_arguments.empty())
	    program_request = program_request + " " + _command_arguments;

	// Run the program
	XLOG_ASSERT(_run_command == NULL);
	_run_command = new RunCommand(
	    _eventloop,
	    _executable_filename,
	    _command_arguments,
	    callback(this, &OpInstance::stdout_cb),
	    callback(this, &OpInstance::stderr_cb),
	    callback(this, &OpInstance::done_cb));
	if (_run_command->execute() != XORP_OK) {
	    delete _run_command;
	    _run_command = NULL;
	    errmsg = c_format("Could not execute program %s",
			      program_request.c_str());
	    success = false;
	    break;
	}
	break;
    } while (false);

    if (! success)
	_done_cb->dispatch(false, errmsg);
}

OpInstance::~OpInstance()
{
    if (_run_command != NULL) {
	delete _run_command;
	_run_command = NULL;
    }
    _op_command.remove_instance(this);
}

void
OpInstance::stdout_cb(RunCommand* run_command, const string& output)
{
    XLOG_ASSERT(run_command == _run_command);
    // XXX: don't accumulate the output, but print it immediately
    _print_cb->dispatch(output);
}

void
OpInstance::stderr_cb(RunCommand* run_command, const string& output)
{
    XLOG_ASSERT(run_command == _run_command);
    // XXX: accumulate the error message and print it later
    _error_msg += output;
}

void
OpInstance::done_cb(RunCommand* run_command, bool success,
		    const string& error_msg)
{
    XLOG_ASSERT(run_command == _run_command);

    if (! success)
	_error_msg += error_msg;

    if (_run_command != NULL) {
	delete _run_command;
	_run_command = NULL;
    }

    execute_done(success);
}

void
OpInstance::execute_done(bool success)
{
    _done_cb->dispatch(success, _error_msg);
    // The callback will delete us. Don't do anything more in this method.
    //    delete this;
}

OpCommand::OpCommand(OpCommandList& ocl, const list<string>& command_parts)
    : _ocl(ocl),
      _command_parts(command_parts)
{
    _command_name = command_parts2command_name(command_parts);
}

void
OpCommand::add_opt_param(const string& opt_param, const string& opt_param_help)
{
    XLOG_ASSERT(_opt_params.find(opt_param) == _opt_params.end());
    _opt_params.insert(make_pair(opt_param, opt_param_help));
}

bool
OpCommand::has_opt_param(const string& opt_param) const
{
    return (_opt_params.find(opt_param) != _opt_params.end());
}

string
OpCommand::str() const
{
    string res = command_name() + "\n";

    if (_command_action.empty()) {
	res += "  No command action specified\n";
    } else {
	res += "  Command: " + _command_action + "\n";
    }

    map<string, string>::const_iterator iter;
    for (iter = _opt_params.begin(); iter != _opt_params.end(); ++iter) {
	res += "  Optional Parameter: " + iter->first;
	res += "  (Parameter Help: )" + iter->second;
	res += "\n";
    }
    return res;
}

string
OpCommand::command_parts2command_name(const list<string>& command_parts)
{
    string res;

    list<string>::const_iterator iter;
    for (iter = command_parts.begin(); iter != command_parts.end(); ++iter) {
	if (iter != command_parts.begin())
	    res += " ";
	res += *iter;
    }
    return res;
}

string
OpCommand::select_positional_argument(const list<string>& arguments,
				      const string& position,
				      string& error_msg)
{
    //
    // Check the positional argument
    //
    if (position.empty()) {
	error_msg = c_format("Empty positional argument");
	return string("");
    }
    if (position[0] != '$') {
	error_msg = c_format("Invalid positional argument \"%s\": "
			     "first symbol is not '$'", position.c_str());
	return string("");
    }
    if (position.size() <= 1) {
	error_msg = c_format("Invalid positional argument \"%s\": "
			     "missing position value", position.c_str());
	return string("");
    }

    //
    // Get the positional argument value
    //
    const string pos_str = position.substr(1, string::npos);
    int pos = atoi(pos_str.c_str());
    if ((pos < 0) || (pos > static_cast<int>(arguments.size()))) {
	error_msg = c_format("Invalid positional argument \"%s\": "
			     "expected values must be in interval "
			     "[0, %u]",
			     position.c_str(),
			     XORP_UINT_CAST(arguments.size()));
	return string("");
    }

    string resolved_str;
    list<string>::const_iterator iter;
    if (pos == 0) {
	// Add all arguments
	for (iter = arguments.begin(); iter != arguments.end(); ++iter) {
	    if (! resolved_str.empty())
		resolved_str += " ";
	    resolved_str += *iter;
	}
    } else {
	// Select a single argument
	int tmp_pos = 0;
	for (iter = arguments.begin(); iter != arguments.end(); ++iter) {
	    tmp_pos++;
	    if (tmp_pos == pos) {
		resolved_str += *iter;
		break;
	    }
	}
    }
    XLOG_ASSERT(! resolved_str.empty());

    return resolved_str;
}

OpInstance *
OpCommand::execute(EventLoop& eventloop, const list<string>& command_line,
		   RouterCLI::OpModePrintCallback print_cb,
		   RouterCLI::OpModeDoneCallback done_cb)
{
    string command_arguments_str;
    list<string>::const_iterator iter;

    if (! is_executable()) {
	done_cb->dispatch(false, "Command is not executable");
	return 0;
    }

    //
    // Add all arguments. If an argument is positional (e.g., $0, $1, etc),
    // then resolve it by using the strings from the command line.
    //
    for (iter = _command_action_arguments.begin();
	 iter != _command_action_arguments.end();
	 ++iter) {
	const string& arg = *iter;
	XLOG_ASSERT(! arg.empty());

	// Add an extra space between arguments
	if (! command_arguments_str.empty())
	    command_arguments_str += " ";

	// If the argument is not positional, then just add it
	if (arg[0] != '$') {
	    command_arguments_str += arg;
	    continue;
	}

	//
	// The argument is positional, hence resolve it using
	// the command-line strings.
	//
	string error_msg;
	string resolved_str = select_positional_argument(command_line, arg,
							 error_msg);
	if (resolved_str.empty()) {
	    XLOG_FATAL("Internal programming error: %s", error_msg.c_str());
	}
	command_arguments_str += resolved_str;
    }

    OpInstance *opinst = new OpInstance(eventloop, *this,
					_command_executable_filename,
					command_arguments_str,
					print_cb, done_cb);
    
    return opinst;
}

bool
OpCommand::command_match(const list<string>& path_parts,
			 SlaveConfigTree* slave_config_tree,
			 bool exact_match) const
{
    list<string>::const_iterator them, us;

    them = path_parts.begin();
    us = _command_parts.begin();

    //
    // First go through the fixed parts of the command
    //
    while (true) {
	if ((them == path_parts.end()) && (us == _command_parts.end())) {
	    return true;
	}
	if (them == path_parts.end()) {
	    if (exact_match)
		return false;
	    else
		return true;
	}
	if (us == _command_parts.end())
		break;

	if ((*us)[0] == '$') {
	    // Matching against a varname
	    list<string> varmatches;
	    slave_config_tree->expand_varname_to_matchlist(*us, varmatches);
	    list<string>::const_iterator vi;
	    bool ok = false;
	    for (vi = varmatches.begin(); vi != varmatches.end(); ++vi) {
		if (*vi == *them) {
		    ok = true;
		    break;
		}
	    }
	    if (ok == false)
		return false;
	} else if ((*us)[0] == '<') {
	    /* any single word matches a wildcard */
	} else if (*them != *us) {
	    return false;
	}
	++them;
	++us;
    }

    //
    // No more fixed parts, try optional parameters
    //
    while (them != path_parts.end()) {
	map<string, string>::const_iterator opi;
	bool ok = false;
	for (opi = _opt_params.begin(); opi != _opt_params.end(); ++opi) {
	    if (opi->first == *them) {
		ok = true;
		break;
	    }
	}
	if (ok == false)
	    return false;
	++them;
    }
    return true;
}

void
OpCommand::get_matches(size_t wordnum, SlaveConfigTree* slave_config_tree,
		       map<string, CliCommandMatch>& return_matches) const
{
    bool is_executable = false;
    bool can_pipe = false;

    if (! _command_action.empty()) {
	is_executable = true;
	can_pipe = true;
    }

    list<string>::const_iterator ci = _command_parts.begin();
    for (size_t i = 0; i < wordnum; i++) {
	++ci;
	if (ci == _command_parts.end())
	    break;
    }

    if (ci == _command_parts.end()) {
	// Add all the optional parameters
	map<string, string>::const_iterator opi;
	for (opi = _opt_params.begin(); opi != _opt_params.end(); ++opi) {
	    const string& command_name = opi->first;
	    const string& help_string = opi->second;
	    CliCommandMatch ccm(command_name, help_string, true, true);
	    return_matches.insert(make_pair(command_name, ccm));
	}
	return;
    }

    string match = *ci;
    do {
	if (match[0] == '$') {
	    XLOG_ASSERT(match[1] == '(');
	    XLOG_ASSERT(match[match.size() - 1] == ')');
	    list<string> var_matches;
	    slave_config_tree->expand_varname_to_matchlist(match, var_matches);
	    list<string>::const_iterator vi;
	    for (vi = var_matches.begin(); vi != var_matches.end(); ++vi) {
		const string& command_name = *vi;
		CliCommandMatch ccm(command_name, _help_string, is_executable,
				    can_pipe);
		return_matches.insert(make_pair(command_name, ccm));
	    }
	    break;
	}
	if (match[0] == '<') {
	    // A mandatory argument that is supplied by the user
	    XLOG_ASSERT(match[match.size() - 1] == '>');
	    const string& command_name = match;
	    CliCommandMatch ccm(command_name, _help_string, is_executable,
				can_pipe);
	    ccm.set_wildcard(true);	// XXX: the argument can be any value
	    return_matches.insert(make_pair(command_name, ccm));
	    break;
	}
	const string& command_name = match;
	CliCommandMatch ccm(command_name, _help_string, is_executable,
			    can_pipe);
	return_matches.insert(make_pair(command_name, ccm));
	break;
    } while (false);
}

void
OpCommand::add_instance(OpInstance* instance)
{
    set<OpInstance*>::iterator iter;

    iter = _instances.find(instance);
    XLOG_ASSERT(iter == _instances.end());

    _instances.insert(instance);
    _ocl.incr_running_op_instances_n();
}

void
OpCommand::remove_instance(OpInstance* instance)
{
    set<OpInstance*>::iterator iter;

    iter = _instances.find(instance);
    XLOG_ASSERT(iter != _instances.end());

    _instances.erase(iter);
    _ocl.decr_running_op_instances_n();
}

OpCommandList::OpCommandList(const string& config_template_dir,
			     const TemplateTree* tt,
			     SlaveModuleManager& mmgr) throw (InitError)
    : _running_op_instances_n(0),
      _mmgr(mmgr)
{
    list<string> files;
    string errmsg;

    _template_tree = tt;

    struct stat dir_data;
    if (stat(config_template_dir.c_str(), &dir_data) < 0) {
	errmsg = c_format("Error reading config directory %s: %s",
			  config_template_dir.c_str(), strerror(errno));
	xorp_throw(InitError, errmsg);
    }

    if ((dir_data.st_mode & S_IFDIR) == 0) {
	errmsg = c_format("Error reading config directory %s: not a directory",
			  config_template_dir.c_str());
	xorp_throw(InitError, errmsg);
    }

    // TODO: file suffix is hardcoded here!
    string globname = config_template_dir + "/*.cmds";
    glob_t pglob;
    if (glob(globname.c_str(), 0, 0, &pglob) != 0) {
	globfree(&pglob);
	errmsg = c_format("Failed to find config files in %s",
			  config_template_dir.c_str());
	xorp_throw(InitError, errmsg);
    }

    if (pglob.gl_pathc == 0) {
	globfree(&pglob);
	errmsg = c_format("Failed to find any template files in %s",
			  config_template_dir.c_str());
	xorp_throw(InitError, errmsg);
    }

    for (size_t i = 0; i < (size_t)pglob.gl_pathc; i++) {
	if (init_opcmd_parser(pglob.gl_pathv[i], this) < 0) {
	    globfree(&pglob);
	    errmsg = c_format("Failed to open template file: %s",
			      config_template_dir.c_str());
	    xorp_throw(InitError, errmsg);
	}
	try {
	    parse_opcmd();
	} catch (const ParseError& pe) {
	    globfree(&pglob);
	    xorp_throw(InitError, pe.why());
	}
	if (_path_segments.size() != 0) {
	    globfree(&pglob);
	    errmsg = c_format("File %s is not terminated properly",
			      pglob.gl_pathv[i]);
	    xorp_throw(InitError, errmsg);
	}
    }

    globfree(&pglob);
}

OpCommandList::~OpCommandList()
{
    while (!_op_commands.empty()) {
	delete _op_commands.front();
	_op_commands.pop_front();
    }
}

bool
OpCommandList::done() const
{
    if (_running_op_instances_n == 0)
	return (true);
    else
	return (false);
}

void
OpCommandList::incr_running_op_instances_n()
{
    _running_op_instances_n++;
}

void
OpCommandList::decr_running_op_instances_n()
{
    XLOG_ASSERT(_running_op_instances_n > 0);
    _running_op_instances_n--;
}

bool
OpCommandList::check_variable_name(const string& variable_name) const
{
    return _template_tree->check_variable_name(variable_name);
}

OpCommand*
OpCommandList::find_op_command(const list<string>& command_parts)
{
    string command_name = OpCommand::command_parts2command_name(command_parts);

    list<OpCommand*>::const_iterator iter;
    for (iter = _op_commands.begin(); iter != _op_commands.end(); ++iter) {
	if ((*iter)->command_name() == command_name)
	    return *iter;
    }
    return NULL;
}

bool
OpCommandList::command_match(const list<string>& command_parts,
			     bool exact_match) const
{
    list<OpCommand*>::const_iterator iter;
    for (iter = _op_commands.begin(); iter != _op_commands.end(); ++iter) {
	if ((*iter)->command_match(command_parts, _slave_config_tree,
				   exact_match))
	    return true;
    }
    return false;
}

OpInstance*
OpCommandList::execute(EventLoop& eventloop, const list<string>& command_parts,
		       RouterCLI::OpModePrintCallback print_cb,
		       RouterCLI::OpModeDoneCallback done_cb) const
{
    list<OpCommand*>::const_iterator iter;
    for (iter = _op_commands.begin(); iter != _op_commands.end(); ++iter) {
	// Find the right command
	if ((*iter)->command_match(command_parts, _slave_config_tree, true)) {
	    // Execute it
	    return (*iter)->execute(eventloop,
				    command_parts, print_cb, done_cb);
	}
    }
    done_cb->dispatch(false, string("No matching command"));
    return 0;
}

OpCommand*
OpCommandList::add_op_command(const OpCommand& op_command)
{
    OpCommand *new_command;

    XLOG_ASSERT(find_op_command(op_command.command_parts()) == NULL);

    new_command = new OpCommand(op_command);
    _op_commands.push_back(new_command);
    return new_command;
}

map<string, string>
OpCommandList::top_level_commands() const
{
    map<string, string> commands;

    //
    // Add the first word of every command, and the help if this
    // indeed is a top-level command
    //
    list<OpCommand*>::const_iterator iter;
    for (iter = _op_commands.begin(); iter != _op_commands.end(); ++iter) {
	const OpCommand* op_command = *iter;
	list<string> path_parts = split(op_command->command_name(), ' ');
	const string& top_command = path_parts.front();
	bool is_top_command = false;

	if (path_parts.size() == 1)
	    is_top_command = true;

	if (is_top_command) {
	    commands.erase(top_command);
	    commands.insert(make_pair(top_command, op_command->help_string()));
	    continue;
	}

	if (commands.find(top_command) == commands.end()) {
	    commands.insert(make_pair(top_command,
				      string("-- no help available --")));
	}
    }
    return commands;
}

map<string, CliCommandMatch>
OpCommandList::childlist(const string& path) const
{
    map<string, CliCommandMatch> children;
    list<string> path_parts = split(path, ' ');

    list<OpCommand*>::const_iterator iter;
    for (iter = _op_commands.begin(); iter != _op_commands.end(); ++iter) {
	const OpCommand* op_command = *iter;
	if (op_command->command_match(path_parts, _slave_config_tree, false)) {
	    //
	    // XXX: If the module has not been started, then don't add its
	    // commands. However, add all commands that are not associated
	    // with any module.
	    //
	    if ((_mmgr.module_is_active(op_command->module()) == false)
		&& (! op_command->module().empty())) {
		continue;
	    }

	    map<string, CliCommandMatch> matches;
	    op_command->get_matches(path_parts.size(), _slave_config_tree,
				    matches);
	    map<string, CliCommandMatch>::iterator mi;
	    for (mi = matches.begin(); mi != matches.end(); ++mi) {
		const string& key = mi->first;
		const CliCommandMatch& ccm = mi->second;
		XLOG_ASSERT(ccm.command_name() != "");
		children.insert(make_pair(key, ccm));
	    }
	}
    }
    return children;
}
