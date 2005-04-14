/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/demo_fea_ifmgr_client_base.hh,v 1.14 2004/06/10 22:42:09 hodson Exp $
 */


#ifndef __XRL_INTERFACES_DEMO_FEA_IFMGR_CLIENT_BASE_HH__
#define __XRL_INTERFACES_DEMO_FEA_IFMGR_CLIENT_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlDemoFeaIfmgrClientTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlDemoFeaIfmgrClientTargetBase {
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
    XrlDemoFeaIfmgrClientTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlDemoFeaIfmgrClientTargetBase();

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
    inline const char* version() const { return "demo_fea_ifmgr_client/0.0"; }

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

    virtual XrlCmdError fea_ifmgr_client_0_1_interface_update(
	// Input values,
	const string&	ifname,
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vif_update(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vifaddr4_update(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	addr,
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_vifaddr6_update(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	event) = 0;

    virtual XrlCmdError fea_ifmgr_client_0_1_updates_completed() = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_ifmgr_client_0_1_interface_update(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vif_update(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vifaddr4_update(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_ifmgr_client_0_1_vifaddr6_update(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_fea_ifmgr_client_0_1_updates_completed(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_DEMO_FEA_IFMGR_CLIENT_BASE_HH__ */
