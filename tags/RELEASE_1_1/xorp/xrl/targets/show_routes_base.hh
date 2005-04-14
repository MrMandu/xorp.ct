/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/show_routes_base.hh,v 1.5 2005/02/15 02:00:51 pavlin Exp $
 */


#ifndef __XRL_INTERFACES_SHOW_ROUTES_BASE_HH__
#define __XRL_INTERFACES_SHOW_ROUTES_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlShowRoutesTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlShowRoutesTargetBase {
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
    XrlShowRoutesTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlShowRoutesTargetBase();

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
    inline const char* version() const { return "show_routes/0.0"; }

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
     *  Announce target birth to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *
     *  @param dst destination network.
     *
     *  @param nexthop nexthop router address.
     *
     *  @param ifname interface name associated with nexthop.
     *
     *  @param vifname virtual interface name with nexthop.
     *
     *  @param metric origin routing protocol metric for route.
     *
     *  @param admin_distance administrative distance of origin routing
     *  protocol.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist4_0_1_add_route(
	// Input values,
	const IPv4Net&	dst,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	cookie) = 0;

    virtual XrlCmdError redist4_0_1_delete_route(
	// Input values,
	const IPv4Net&	network,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  When route redistribution begins, the receiver is sent the existing
     *  list of routes. This message marks the beginning of the routes being
     *  sent.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist4_0_1_starting_route_dump(
	// Input values,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  When route redistribution begins, the receiver is sent the existing
     *  list of routes. This message marks the end of the existing routes being
     *  sent.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist4_0_1_finishing_route_dump(
	// Input values,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *
     *  @param dst destination network.
     *
     *  @param nexthop nexthop router address.
     *
     *  @param ifname interface name associated with nexthop.
     *
     *  @param vifname virtual interface name with nexthop.
     *
     *  @param metric origin routing protocol metric for route.
     *
     *  @param admin_distance administrative distance of origin routing
     *  protocol.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist6_0_1_add_route(
	// Input values,
	const IPv6Net&	dst,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	cookie) = 0;

    virtual XrlCmdError redist6_0_1_delete_route(
	// Input values,
	const IPv6Net&	network,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  When route redistribution begins, the receiver is sent the existing
     *  list of routes. This message marks the beginning of the routes being
     *  sent.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist6_0_1_starting_route_dump(
	// Input values,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  When route redistribution begins, the receiver is sent the existing
     *  list of routes. This message marks the end of the existing routes being
     *  sent.
     *
     *  @param cookie value set by the requestor to identify redistribution
     *  source. Typical value is the originating protocol name.
     */
    virtual XrlCmdError redist6_0_1_finishing_route_dump(
	// Input values,
	const string&	cookie) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist4_0_1_add_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist4_0_1_delete_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist4_0_1_starting_route_dump(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist4_0_1_finishing_route_dump(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist6_0_1_add_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist6_0_1_delete_route(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist6_0_1_starting_route_dump(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_redist6_0_1_finishing_route_dump(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_SHOW_ROUTES_BASE_HH__ */
