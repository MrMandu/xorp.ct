/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/mfea_base.hh,v 1.23 2004/06/10 22:42:12 hodson Exp $
 */


#ifndef __XRL_INTERFACES_MFEA_BASE_HH__
#define __XRL_INTERFACES_MFEA_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlMfeaTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlMfeaTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlMfeaTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlMfeaTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "mfea/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Process a CLI command.
     *
     *  @param processor_name the processor name for this command.
     *
     *  @param cli_term_name the terminal name the command was entered from.
     *
     *  @param cli_session_id the CLI session ID the command was entered from.
     *
     *  @param command_name the command name to process.
     *
     *  @param command_args the command arguments to process.
     *
     *  @param ret_processor_name the processor name to return back to the CLI.
     *
     *  @param ret_cli_term_name the terminal name to return back.
     *
     *  @param ret_cli_session_id the CLI session ID to return back.
     *
     *  @param ret_command_output the command output to return back.
     */
    virtual XrlCmdError cli_processor_0_1_process_command(
	// Input values,
	const string&	processor_name,
	const string&	cli_term_name,
	const uint32_t&	cli_session_id,
	const string&	command_name,
	const string&	command_args,
	// Output values,
	string&	ret_processor_name,
	string&	ret_cli_term_name,
	uint32_t&	ret_cli_session_id,
	string&	ret_command_output) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Test if the underlying system supports IPv4 multicast routing.
     *
     *  @param result true if the underlying system supports IPv4 multicast
     *  routing, otherwise false.
     */
    virtual XrlCmdError mfea_0_1_have_multicast_routing4(
	// Output values,
	bool&	result) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Test if the underlying system supports IPv6 multicast routing.
     *
     *  @param result true if the underlying system supports IPv6 multicast
     *  routing, otherwise false.
     */
    virtual XrlCmdError mfea_0_1_have_multicast_routing6(
	// Output values,
	bool&	result) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/delete a protocol in the Multicast FEA.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol to add/delete.
     *
     *  @param protocol_id the ID of the protocol to add/delete (both sides
     *  must agree on the particular values).
     */
    virtual XrlCmdError mfea_0_1_add_protocol4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id) = 0;

    virtual XrlCmdError mfea_0_1_add_protocol6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id) = 0;

    virtual XrlCmdError mfea_0_1_delete_protocol4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id) = 0;

    virtual XrlCmdError mfea_0_1_delete_protocol6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Start/stop a protocol on an interface in the Multicast FEA.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol to start/stop on the
     *  particular vif.
     *
     *  @param protocol_id the ID of the protocol to add/stop on the particular
     *  vif (both sides must agree on the particular values).
     *
     *  @param vif_name the name of the vif to start/stop for the particular
     *  protocol.
     *
     *  @param vif_index the index of the vif to start/stop for the particular
     *  protocol.
     */
    virtual XrlCmdError mfea_0_1_start_protocol_vif4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index) = 0;

    virtual XrlCmdError mfea_0_1_start_protocol_vif6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index) = 0;

    virtual XrlCmdError mfea_0_1_stop_protocol_vif4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index) = 0;

    virtual XrlCmdError mfea_0_1_stop_protocol_vif6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable the receiving of kernel-originated signal messages.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol to add.
     *
     *  @param protocol_id the ID of the protocol to add (both sides must agree
     *  on the particular values).
     *
     *  @param is_allow if true, enable the receiving of kernel-originated
     *  signal messages by protocol 'protocol_name'.
     */
    virtual XrlCmdError mfea_0_1_allow_signal_messages(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const bool&	is_allow) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Join/leave a multicast group.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol that joins/leave the
     *  group.
     *
     *  @param protocol_id the ID of the protocol that joins/leave the group
     *  (both sides must agree on the particular values).
     *
     *  @param vif_name the name of the vif to join/leave the multicast group.
     *
     *  @param vif_index the index of the vif to join/leave the multicast
     *  group.
     *
     *  @param group_address the multicast group to join/leave.
     */
    virtual XrlCmdError mfea_0_1_join_multicast_group4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	group_address) = 0;

    virtual XrlCmdError mfea_0_1_join_multicast_group6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	group_address) = 0;

    virtual XrlCmdError mfea_0_1_leave_multicast_group4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	group_address) = 0;

    virtual XrlCmdError mfea_0_1_leave_multicast_group6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	group_address) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/delete a Multicast Forwarding Cache with the kernel.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param source_address the source address of the MFC to add/delete.
     *
     *  @param group_address the group address of the MFC to add/delete.
     *
     *  @param iif_vif_index the index of the vif that is the incoming
     *  interface.
     *
     *  @param oiflist the bit-vector with the set of outgoing interfaces.
     *
     *  @param oiflist_disable_wrongvif the bit-vector with the set of outgoing
     *  interfaces to disable WRONGVIF kernel signal.
     *
     *  @param max_vifs_oiflist the number of vifs covered by oiflist or
     *  oiflist_disable_wrongvif .
     *
     *  @param rp_address the RP address of the MFC to add.
     */
    virtual XrlCmdError mfea_0_1_add_mfc4(
	// Input values,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	iif_vif_index,
	const vector<uint8_t>&	oiflist,
	const vector<uint8_t>&	oiflist_disable_wrongvif,
	const uint32_t&	max_vifs_oiflist,
	const IPv4&	rp_address) = 0;

    virtual XrlCmdError mfea_0_1_add_mfc6(
	// Input values,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	iif_vif_index,
	const vector<uint8_t>&	oiflist,
	const vector<uint8_t>&	oiflist_disable_wrongvif,
	const uint32_t&	max_vifs_oiflist,
	const IPv6&	rp_address) = 0;

    virtual XrlCmdError mfea_0_1_delete_mfc4(
	// Input values,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address) = 0;

    virtual XrlCmdError mfea_0_1_delete_mfc6(
	// Input values,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Send a protocol message to the MFEA.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol that sends a message.
     *
     *  @param protocol_id the ID of the protocol that sends a message (both
     *  sides must agree on the particular values).
     *
     *  @param vif_name the name of the vif to send the message.
     *
     *  @param vif_index the vif index of the vif to send the message.
     *
     *  @param source_address the address of the sender.
     *
     *  @param dest_address the destination address.
     *
     *  @param ip_ttl the TTL of the IP packet to send. If it has a negative
     *  value, the TTL will be set by the lower layers.
     *
     *  @param ip_tos the TOS of the IP packet to send. If it has a negative
     *  value, the TOS will be set by the lower layers.
     *
     *  @param is_router_alert set/reset the IP Router Alert option in the IP
     *  packet to send (when applicable).
     */
    virtual XrlCmdError mfea_0_1_send_protocol_message4(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	source_address,
	const IPv4&	dest_address,
	const int32_t&	ip_ttl,
	const int32_t&	ip_tos,
	const bool&	is_router_alert,
	const vector<uint8_t>&	protocol_message) = 0;

    virtual XrlCmdError mfea_0_1_send_protocol_message6(
	// Input values,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	source_address,
	const IPv6&	dest_address,
	const int32_t&	ip_ttl,
	const int32_t&	ip_tos,
	const bool&	is_router_alert,
	const vector<uint8_t>&	protocol_message) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/delete a dataflow monitor with the MFEA.
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param source_address the source address of the dataflow to start/stop
     *  monitoring.
     *
     *  @param group_address the group address of the dataflow to start/stop
     *  monitoring.
     *
     *  @param threshold_interval_sec the number of seconds in the interval to
     *  measure.
     *
     *  @param threshold_interval_usec the number of microseconds in the
     *  interval to measure.
     *
     *  @param threshold_packets the threshold (in number of packets) to
     *  compare against.
     *
     *  @param threshold_bytes the threshold (in number of bytes) to compare
     *  against.
     *
     *  @param is_threshold_in_packets if true, threshold_packets is valid.
     *
     *  @param is_threshold_in_bytes if true, threshold_bytes is valid.
     *
     *  @param is_geq_upcall if true, the operation for comparison is ">=".
     *
     *  @param is_leq_upcall if true, the operation for comparison is "<=".
     */
    virtual XrlCmdError mfea_0_1_add_dataflow_monitor4(
	// Input values,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall) = 0;

    virtual XrlCmdError mfea_0_1_add_dataflow_monitor6(
	// Input values,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall) = 0;

    virtual XrlCmdError mfea_0_1_delete_dataflow_monitor4(
	// Input values,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall) = 0;

    virtual XrlCmdError mfea_0_1_delete_dataflow_monitor6(
	// Input values,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall) = 0;

    virtual XrlCmdError mfea_0_1_delete_all_dataflow_monitor4(
	// Input values,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address) = 0;

    virtual XrlCmdError mfea_0_1_delete_all_dataflow_monitor6(
	// Input values,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop a MFEA vif interface.
     *
     *  @param vif_name the name of the vif to enable/disable/start/stop.
     *
     *  @param enable if true, then enable the vif, otherwise disable it.
     */
    virtual XrlCmdError mfea_0_1_enable_vif(
	// Input values,
	const string&	vif_name,
	const bool&	enable) = 0;

    virtual XrlCmdError mfea_0_1_start_vif(
	// Input values,
	const string&	vif_name) = 0;

    virtual XrlCmdError mfea_0_1_stop_vif(
	// Input values,
	const string&	vif_name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop all MFEA vif interfaces.
     *
     *  @param enable if true, then enable the vifs, otherwise disable them.
     */
    virtual XrlCmdError mfea_0_1_enable_all_vifs(
	// Input values,
	const bool&	enable) = 0;

    virtual XrlCmdError mfea_0_1_start_all_vifs() = 0;

    virtual XrlCmdError mfea_0_1_stop_all_vifs() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop the MFEA.
     *
     *  @param enable if true, then enable the MFEA, otherwise disable it.
     */
    virtual XrlCmdError mfea_0_1_enable_mfea(
	// Input values,
	const bool&	enable) = 0;

    virtual XrlCmdError mfea_0_1_start_mfea() = 0;

    virtual XrlCmdError mfea_0_1_stop_mfea() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop the MFEA CLI access.
     *
     *  @param enable if true, then enable the MFEA CLI access, otherwise
     *  disable it.
     */
    virtual XrlCmdError mfea_0_1_enable_cli(
	// Input values,
	const bool&	enable) = 0;

    virtual XrlCmdError mfea_0_1_start_cli() = 0;

    virtual XrlCmdError mfea_0_1_stop_cli() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable the MFEA trace log for all operations.
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    virtual XrlCmdError mfea_0_1_log_trace_all(
	// Input values,
	const bool&	enable) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_cli_processor_0_1_process_command(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_have_multicast_routing4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_have_multicast_routing6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_protocol4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_protocol6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_protocol4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_protocol6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_protocol_vif4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_protocol_vif6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_protocol_vif4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_protocol_vif6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_allow_signal_messages(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_join_multicast_group4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_join_multicast_group6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_leave_multicast_group4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_leave_multicast_group6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_mfc4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_mfc6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_mfc4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_mfc6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_send_protocol_message4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_send_protocol_message6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_dataflow_monitor4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_add_dataflow_monitor6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_dataflow_monitor4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_dataflow_monitor6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_all_dataflow_monitor4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_delete_all_dataflow_monitor6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_enable_vif(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_vif(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_vif(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_enable_all_vifs(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_all_vifs(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_all_vifs(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_enable_mfea(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_mfea(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_mfea(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_enable_cli(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_start_cli(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_stop_cli(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_mfea_0_1_log_trace_all(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_MFEA_BASE_HH__ */
