/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/ospf_xif.hh,v 1.10 2004/06/10 22:42:03 hodson Exp $
 */

#ifndef __XRL_INTERFACES_OSPF_XIF_HH__
#define __XRL_INTERFACES_OSPF_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifOspf"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlOspfV0p1Client {
public:
    XrlOspfV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlOspfV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetRouterIdCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set router id
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_router_id(
	const char*	target_name,
	const uint32_t&	id,
	const SetRouterIdCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetRouterIdCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get router id
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_router_id(
	const char*	target_name,
	const GetRouterIdCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetLsdbLimitCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set maximum number of AS-external LSA's
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_lsdb_limit(
	const char*	target_name,
	const int32_t&	limit,
	const SetLsdbLimitCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr GetLsdbLimitCB;

    bool send_get_lsdb_limit(
	const char*	target_name,
	const GetLsdbLimitCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetMospfCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable / disable MOSPF
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_mospf(
	const char*	target_name,
	const bool&	enabled,
	const SetMospfCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetMospfCB;

    bool send_get_mospf(
	const char*	target_name,
	const GetMospfCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetInterareaMcCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable / Disable Inter-area multicast
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_interarea_mc(
	const char*	target_name,
	const bool&	enabled,
	const SetInterareaMcCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetInterareaMcCB;

    bool send_get_interarea_mc(
	const char*	target_name,
	const GetInterareaMcCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetOverflowIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set time to exit overflow state
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_overflow_interval(
	const char*	target_name,
	const int32_t&	ovfl_int,
	const SetOverflowIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr GetOverflowIntervalCB;

    bool send_get_overflow_interval(
	const char*	target_name,
	const GetOverflowIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetFloodRateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set flood rate - self orig per second
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_flood_rate(
	const char*	target_name,
	const int32_t&	rate,
	const SetFloodRateCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr GetFloodRateCB;

    bool send_get_flood_rate(
	const char*	target_name,
	const GetFloodRateCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetMaxRxmtWindowCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set back-to-back retransmissions
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_max_rxmt_window(
	const char*	target_name,
	const uint32_t&	window,
	const SetMaxRxmtWindowCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetMaxRxmtWindowCB;

    bool send_get_max_rxmt_window(
	const char*	target_name,
	const GetMaxRxmtWindowCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetMaxDdsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set maximum simultaneous DB exchanges
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_max_dds(
	const char*	target_name,
	const uint32_t&	max_dds,
	const SetMaxDdsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetMaxDdsCB;

    bool send_get_max_dds(
	const char*	target_name,
	const GetMaxDdsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetLsaRefreshRateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set rate to refresh DoNotAge LSAs
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_lsa_refresh_rate(
	const char*	target_name,
	const uint32_t&	rate,
	const SetLsaRefreshRateCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetLsaRefreshRateCB;

    bool send_get_lsa_refresh_rate(
	const char*	target_name,
	const GetLsaRefreshRateCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetP2PAdjLimitCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the maximum number of point-to-point links that will become
     *  adjacent to a particular neighbor. If there is no limit then value is
     *  zero.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_p2p_adj_limit(
	const char*	target_name,
	const uint32_t&	max_adj,
	const SetP2PAdjLimitCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetP2PAdjLimitCB;

    bool send_get_p2p_adj_limit(
	const char*	target_name,
	const GetP2PAdjLimitCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetRandomRefreshCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set randomized LSA refreshes
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_random_refresh(
	const char*	target_name,
	const bool&	enabled,
	const SetRandomRefreshCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetRandomRefreshCB;

    bool send_get_random_refresh(
	const char*	target_name,
	const GetRandomRefreshCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddOrConfigureAreaCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create area
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_add_or_configure_area(
	const char*	target_name,
	const uint32_t&	area_id,
	const bool&	is_stub,
	const uint32_t&	default_cost,
	const bool&	import_summary_routes,
	const AddOrConfigureAreaCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAreaCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete area
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_area(
	const char*	target_name,
	const uint32_t&	area_id,
	const DeleteAreaCB&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const bool*, const uint32_t*, const bool*>::RefPtr QueryAreaCB;
    /**
     *  Send Xrl intended to:
     *
     *  Query area options
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_query_area(
	const char*	target_name,
	const uint32_t&	area_id,
	const QueryAreaCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ListAreaIdsCB;
    /**
     *  Send Xrl intended to:
     *
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_list_area_ids(
	const char*	target_name,
	const ListAreaIdsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddOrConfigureAggregateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add or configure aggregate.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param area_id id of area aggregate belongs to.
     *
     *  @param network network identifier.
     *
     *  @param netmask netmask identifier.
     *
     *  @param suppress_advertisement of aggregate.
     */
    bool send_add_or_configure_aggregate(
	const char*	target_name,
	const uint32_t&	area_id,
	const IPv4&	network,
	const IPv4&	netmask,
	const bool&	suppress_advertisement,
	const AddOrConfigureAggregateCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAggregateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete aggregate identified by area_id, network, and netmask
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_aggregate(
	const char*	target_name,
	const uint32_t&	area_id,
	const IPv4&	network,
	const IPv4&	netmask,
	const DeleteAggregateCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr QueryAggregateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Query aggregate identified by area_id, network, and netmask
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_query_aggregate(
	const char*	target_name,
	const uint32_t&	area_id,
	const IPv4&	network,
	const IPv4&	netmask,
	const QueryAggregateCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const XrlAtomList*, const XrlAtomList*>::RefPtr ListAggregatesCB;
    /**
     *  Send Xrl intended to:
     *
     *  Return list of aggregate identifiers for area identified by area_id.
     *  Two lists are returned, the nth elements in each list comprise the
     *  tuple (network,netmask) that uniquely identifies the aggregate within
     *  the area.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_list_aggregates(
	const char*	target_name,
	const uint32_t&	area_id,
	const ListAggregatesCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddOrConfigureHostCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add or configure host routes.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param area_id host is to be advertised in.
     *
     *  @param cost metric associated with host (0-65535).
     */
    bool send_add_or_configure_host(
	const char*	target_name,
	const IPv4&	network,
	const IPv4&	netmask,
	const uint32_t&	area_id,
	const uint32_t&	cost,
	const AddOrConfigureHostCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteHostCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete host identified by network and netmask
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_host(
	const char*	target_name,
	const IPv4&	network,
	const IPv4&	netmask,
	const uint32_t&	area_id,
	const DeleteHostCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr QueryHostCB;
    /**
     *  Send Xrl intended to:
     *
     *  Query host identified by network and netmask
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_query_host(
	const char*	target_name,
	const IPv4&	network,
	const IPv4&	netmask,
	const uint32_t&	area_id,
	const QueryHostCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const XrlAtomList*, const XrlAtomList*>::RefPtr ListHostsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Return list of host identifiers for area identified by area_id. Two
     *  lists are returned, the nth elements in each list comprise the tuple
     *  (network,netmask) that uniquely identifies the host within the area.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_list_hosts(
	const char*	target_name,
	const uint32_t&	area_id,
	const ListHostsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddVlinkCB;

    bool send_add_vlink(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const AddVlinkCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteVlinkCB;

    bool send_delete_vlink(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const DeleteVlinkCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VlinkSetTransmitDelayCB;

    bool send_vlink_set_transmit_delay(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const uint32_t&	delay_secs,
	const VlinkSetTransmitDelayCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr VlinkGetTransmitDelayCB;

    bool send_vlink_get_transmit_delay(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const VlinkGetTransmitDelayCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VlinkSetRetransmitIntervalCB;

    bool send_vlink_set_retransmit_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const uint32_t&	interval_secs,
	const VlinkSetRetransmitIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr VlinkGetRetransmitIntervalCB;

    bool send_vlink_get_retransmit_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const VlinkGetRetransmitIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VlinkSetHelloIntervalCB;

    bool send_vlink_set_hello_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const uint32_t&	interval_secs,
	const VlinkSetHelloIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr VlinkGetHelloIntervalCB;

    bool send_vlink_get_hello_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const VlinkGetHelloIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VlinkSetRouterDeadIntervalCB;

    bool send_vlink_set_router_dead_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const uint32_t&	interval_secs,
	const VlinkSetRouterDeadIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr VlinkGetRouterDeadIntervalCB;

    bool send_vlink_get_router_dead_interval(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const VlinkGetRouterDeadIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr VlinkSetAuthenticationCB;
    /**
     *  Send Xrl intended to:
     *
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param type is one of "none", "cleartext", "md5"
     */
    bool send_vlink_set_authentication(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const string&	type,
	const string&	key,
	const VlinkSetAuthenticationCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const string*, const string*>::RefPtr VlinkGetAuthenticationCB;

    bool send_vlink_get_authentication(
	const char*	target_name,
	const uint32_t&	transit_area,
	const uint32_t&	neighbor_id,
	const VlinkGetAuthenticationCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ListVlinksCB;
    /**
     *  Send Xrl intended to:
     *
     *  Return list of neighbour id's (unsigned 32 bit values)
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_list_vlinks(
	const char*	target_name,
	const uint32_t&	transit_id,
	const ListVlinksCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddOrConfigureExternalRouteCB;

    bool send_add_or_configure_external_route(
	const char*	target_name,
	const IPv4Net&	network,
	const IPv4&	gateway,
	const uint32_t&	type,
	const uint32_t&	cost,
	const bool&	multicast,
	const uint32_t&	external_route_tag,
	const AddOrConfigureExternalRouteCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteExternalRouteCB;

    bool send_delete_external_route(
	const char*	target_name,
	const IPv4Net&	network,
	const IPv4&	gateway,
	const DeleteExternalRouteCB&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const uint32_t*, const uint32_t*, const bool*, const uint32_t*>::RefPtr QueryExternalRouteCB;

    bool send_query_external_route(
	const char*	target_name,
	const IPv4Net&	network,
	const IPv4&	gateway,
	const QueryExternalRouteCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ListExternalRoutesCB;

    bool send_list_external_routes(
	const char*	target_name,
	const IPv4Net&	network,
	const ListExternalRoutesCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddInterfaceCB;

    bool send_add_interface(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	if_index,
	const uint32_t&	area_id,
	const uint32_t&	cost,
	const uint32_t&	mtu,
	const string&	type,
	const bool&	on_demand,
	const bool&	passive,
	const AddInterfaceCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetIfIndexCB;

    bool send_interface_set_if_index(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	index,
	const InterfaceSetIfIndexCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetIfIndexCB;

    bool send_interface_get_if_index(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetIfIndexCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetAreaIdCB;

    bool send_interface_set_area_id(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	area_id,
	const InterfaceSetAreaIdCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetAreaIdCB;

    bool send_interface_get_area_id(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetAreaIdCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetCostCB;

    bool send_interface_set_cost(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	cost,
	const InterfaceSetCostCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetCostCB;

    bool send_interface_get_cost(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetCostCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetMtuCB;

    bool send_interface_set_mtu(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	mtu,
	const InterfaceSetMtuCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetMtuCB;

    bool send_interface_get_mtu(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetMtuCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetTypeCB;

    bool send_interface_set_type(
	const char*	target_name,
	const string&	identifier,
	const string&	type,
	const InterfaceSetTypeCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr InterfaceGetTypeCB;

    bool send_interface_get_type(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetTypeCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetDrPriorityCB;

    bool send_interface_set_dr_priority(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	dr_priority,
	const InterfaceSetDrPriorityCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetDrPriorityCB;

    bool send_interface_get_dr_priority(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetDrPriorityCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetTransitDelayCB;

    bool send_interface_set_transit_delay(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	delay_secs,
	const InterfaceSetTransitDelayCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetTransitDelayCB;

    bool send_interface_get_transit_delay(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetTransitDelayCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetRetransmitIntervalCB;

    bool send_interface_set_retransmit_interval(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	interval_secs,
	const InterfaceSetRetransmitIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetRetransmitIntervalCB;

    bool send_interface_get_retransmit_interval(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetRetransmitIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetRouterDeadIntervalCB;

    bool send_interface_set_router_dead_interval(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	interval_secs,
	const InterfaceSetRouterDeadIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetRouterDeadIntervalCB;

    bool send_interface_get_router_dead_interval(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetRouterDeadIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetPollIntervalCB;

    bool send_interface_set_poll_interval(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	interval_secs,
	const InterfaceSetPollIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr InterfaceGetPollIntervalCB;

    bool send_interface_get_poll_interval(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetPollIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetAuthenticationCB;

    bool send_interface_set_authentication(
	const char*	target_name,
	const string&	identifier,
	const string&	type,
	const string&	key,
	const InterfaceSetAuthenticationCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const string*, const string*>::RefPtr InterfaceGetAuthenticationCB;

    bool send_interface_get_authentication(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetAuthenticationCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetMulticastForwardingCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set state of multicast forwarding on interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param type multicast type can be one of three values: "blocked"
     *  meaning not enabled, "multicast" meaning data-link multicast, or
     *  "unicast" meaning multicast packets should be unicast on data-link.
     */
    bool send_interface_set_multicast_forwarding(
	const char*	target_name,
	const string&	identifier,
	const string&	type,
	const InterfaceSetMulticastForwardingCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr InterfaceGetMulticastForwardingCB;

    bool send_interface_get_multicast_forwarding(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetMulticastForwardingCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetOnDemandCB;

    bool send_interface_set_on_demand(
	const char*	target_name,
	const string&	identifier,
	const bool&	on_demand,
	const InterfaceSetOnDemandCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr InterfaceGetOnDemandCB;

    bool send_interface_get_on_demand(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetOnDemandCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetPassiveCB;

    bool send_interface_set_passive(
	const char*	target_name,
	const string&	identifier,
	const bool&	passive,
	const InterfaceSetPassiveCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr InterfaceGetPassiveCB;

    bool send_interface_get_passive(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetPassiveCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceSetIgmpCB;

    bool send_interface_set_igmp(
	const char*	target_name,
	const string&	identifier,
	const bool&	enabled,
	const InterfaceSetIgmpCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr InterfaceGetIgmpCB;

    bool send_interface_get_igmp(
	const char*	target_name,
	const string&	identifier,
	const InterfaceGetIgmpCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteInterfaceCB;

    bool send_delete_interface(
	const char*	target_name,
	const string&	identifier,
	const DeleteInterfaceCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ListInterfacesCB;

    bool send_list_interfaces(
	const char*	target_name,
	const ListInterfacesCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceAddMd5KeyCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add md5 key to interface. The key may be used for both receiving and
     *  transmitting packets. Separate time periods are used to describe when
     *  the key is valid for receiving and transmitting. These periods are
     *  bound by times start_receive, stop_receive and start_transmit,
     *  stop_transmit. The expected date format is "%Y-%m-%d %H:%M:%S". This
     *  code uses strptime and strftime internally.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param identifier interface key is to be used for.
     *
     *  @param key_id a value between 1-255 that identifies the key.
     */
    bool send_interface_add_md5_key(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	key_id,
	const string&	md5key,
	const string&	start_receive,
	const string&	stop_receive,
	const string&	start_transmit,
	const string&	stop_transmit,
	const InterfaceAddMd5KeyCB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const string*, const string*, const string*, const string*, const string*>::RefPtr InterfaceGetMd5KeyCB;

    bool send_interface_get_md5_key(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	key_id,
	const InterfaceGetMd5KeyCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr InterfaceDeleteMd5KeyCB;

    bool send_interface_delete_md5_key(
	const char*	target_name,
	const string&	identifier,
	const uint32_t&	key_id,
	const InterfaceDeleteMd5KeyCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr InterfaceListMd5KeysCB;

    bool send_interface_list_md5_keys(
	const char*	target_name,
	const string&	identifier,
	const InterfaceListMd5KeysCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddNeighborCB;

    bool send_add_neighbor(
	const char*	target_name,
	const IPv4&	nbr_addr,
	const bool&	dr_eligible,
	const AddNeighborCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetNeighborCB;

    bool send_get_neighbor(
	const char*	target_name,
	const IPv4&	nbr_addr,
	const GetNeighborCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteNeighborCB;

    bool send_delete_neighbor(
	const char*	target_name,
	const IPv4&	nbr_addr,
	const DeleteNeighborCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ListNeighborsCB;

    bool send_list_neighbors(
	const char*	target_name,
	const ListNeighborsCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_set_router_id(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouterIdCB		cb
    );

    void unmarshall_get_router_id(
	const XrlError&	e,
	XrlArgs*	a,
	GetRouterIdCB		cb
    );

    void unmarshall_set_lsdb_limit(
	const XrlError&	e,
	XrlArgs*	a,
	SetLsdbLimitCB		cb
    );

    void unmarshall_get_lsdb_limit(
	const XrlError&	e,
	XrlArgs*	a,
	GetLsdbLimitCB		cb
    );

    void unmarshall_set_mospf(
	const XrlError&	e,
	XrlArgs*	a,
	SetMospfCB		cb
    );

    void unmarshall_get_mospf(
	const XrlError&	e,
	XrlArgs*	a,
	GetMospfCB		cb
    );

    void unmarshall_set_interarea_mc(
	const XrlError&	e,
	XrlArgs*	a,
	SetInterareaMcCB		cb
    );

    void unmarshall_get_interarea_mc(
	const XrlError&	e,
	XrlArgs*	a,
	GetInterareaMcCB		cb
    );

    void unmarshall_set_overflow_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetOverflowIntervalCB		cb
    );

    void unmarshall_get_overflow_interval(
	const XrlError&	e,
	XrlArgs*	a,
	GetOverflowIntervalCB		cb
    );

    void unmarshall_set_flood_rate(
	const XrlError&	e,
	XrlArgs*	a,
	SetFloodRateCB		cb
    );

    void unmarshall_get_flood_rate(
	const XrlError&	e,
	XrlArgs*	a,
	GetFloodRateCB		cb
    );

    void unmarshall_set_max_rxmt_window(
	const XrlError&	e,
	XrlArgs*	a,
	SetMaxRxmtWindowCB		cb
    );

    void unmarshall_get_max_rxmt_window(
	const XrlError&	e,
	XrlArgs*	a,
	GetMaxRxmtWindowCB		cb
    );

    void unmarshall_set_max_dds(
	const XrlError&	e,
	XrlArgs*	a,
	SetMaxDdsCB		cb
    );

    void unmarshall_get_max_dds(
	const XrlError&	e,
	XrlArgs*	a,
	GetMaxDdsCB		cb
    );

    void unmarshall_set_lsa_refresh_rate(
	const XrlError&	e,
	XrlArgs*	a,
	SetLsaRefreshRateCB		cb
    );

    void unmarshall_get_lsa_refresh_rate(
	const XrlError&	e,
	XrlArgs*	a,
	GetLsaRefreshRateCB		cb
    );

    void unmarshall_set_p2p_adj_limit(
	const XrlError&	e,
	XrlArgs*	a,
	SetP2PAdjLimitCB		cb
    );

    void unmarshall_get_p2p_adj_limit(
	const XrlError&	e,
	XrlArgs*	a,
	GetP2PAdjLimitCB		cb
    );

    void unmarshall_set_random_refresh(
	const XrlError&	e,
	XrlArgs*	a,
	SetRandomRefreshCB		cb
    );

    void unmarshall_get_random_refresh(
	const XrlError&	e,
	XrlArgs*	a,
	GetRandomRefreshCB		cb
    );

    void unmarshall_add_or_configure_area(
	const XrlError&	e,
	XrlArgs*	a,
	AddOrConfigureAreaCB		cb
    );

    void unmarshall_delete_area(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAreaCB		cb
    );

    void unmarshall_query_area(
	const XrlError&	e,
	XrlArgs*	a,
	QueryAreaCB		cb
    );

    void unmarshall_list_area_ids(
	const XrlError&	e,
	XrlArgs*	a,
	ListAreaIdsCB		cb
    );

    void unmarshall_add_or_configure_aggregate(
	const XrlError&	e,
	XrlArgs*	a,
	AddOrConfigureAggregateCB		cb
    );

    void unmarshall_delete_aggregate(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAggregateCB		cb
    );

    void unmarshall_query_aggregate(
	const XrlError&	e,
	XrlArgs*	a,
	QueryAggregateCB		cb
    );

    void unmarshall_list_aggregates(
	const XrlError&	e,
	XrlArgs*	a,
	ListAggregatesCB		cb
    );

    void unmarshall_add_or_configure_host(
	const XrlError&	e,
	XrlArgs*	a,
	AddOrConfigureHostCB		cb
    );

    void unmarshall_delete_host(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteHostCB		cb
    );

    void unmarshall_query_host(
	const XrlError&	e,
	XrlArgs*	a,
	QueryHostCB		cb
    );

    void unmarshall_list_hosts(
	const XrlError&	e,
	XrlArgs*	a,
	ListHostsCB		cb
    );

    void unmarshall_add_vlink(
	const XrlError&	e,
	XrlArgs*	a,
	AddVlinkCB		cb
    );

    void unmarshall_delete_vlink(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVlinkCB		cb
    );

    void unmarshall_vlink_set_transmit_delay(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkSetTransmitDelayCB		cb
    );

    void unmarshall_vlink_get_transmit_delay(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkGetTransmitDelayCB		cb
    );

    void unmarshall_vlink_set_retransmit_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkSetRetransmitIntervalCB		cb
    );

    void unmarshall_vlink_get_retransmit_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkGetRetransmitIntervalCB		cb
    );

    void unmarshall_vlink_set_hello_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkSetHelloIntervalCB		cb
    );

    void unmarshall_vlink_get_hello_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkGetHelloIntervalCB		cb
    );

    void unmarshall_vlink_set_router_dead_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkSetRouterDeadIntervalCB		cb
    );

    void unmarshall_vlink_get_router_dead_interval(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkGetRouterDeadIntervalCB		cb
    );

    void unmarshall_vlink_set_authentication(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkSetAuthenticationCB		cb
    );

    void unmarshall_vlink_get_authentication(
	const XrlError&	e,
	XrlArgs*	a,
	VlinkGetAuthenticationCB		cb
    );

    void unmarshall_list_vlinks(
	const XrlError&	e,
	XrlArgs*	a,
	ListVlinksCB		cb
    );

    void unmarshall_add_or_configure_external_route(
	const XrlError&	e,
	XrlArgs*	a,
	AddOrConfigureExternalRouteCB		cb
    );

    void unmarshall_delete_external_route(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteExternalRouteCB		cb
    );

    void unmarshall_query_external_route(
	const XrlError&	e,
	XrlArgs*	a,
	QueryExternalRouteCB		cb
    );

    void unmarshall_list_external_routes(
	const XrlError&	e,
	XrlArgs*	a,
	ListExternalRoutesCB		cb
    );

    void unmarshall_add_interface(
	const XrlError&	e,
	XrlArgs*	a,
	AddInterfaceCB		cb
    );

    void unmarshall_interface_set_if_index(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetIfIndexCB		cb
    );

    void unmarshall_interface_get_if_index(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetIfIndexCB		cb
    );

    void unmarshall_interface_set_area_id(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetAreaIdCB		cb
    );

    void unmarshall_interface_get_area_id(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetAreaIdCB		cb
    );

    void unmarshall_interface_set_cost(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetCostCB		cb
    );

    void unmarshall_interface_get_cost(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetCostCB		cb
    );

    void unmarshall_interface_set_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetMtuCB		cb
    );

    void unmarshall_interface_get_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetMtuCB		cb
    );

    void unmarshall_interface_set_type(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetTypeCB		cb
    );

    void unmarshall_interface_get_type(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetTypeCB		cb
    );

    void unmarshall_interface_set_dr_priority(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetDrPriorityCB		cb
    );

    void unmarshall_interface_get_dr_priority(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetDrPriorityCB		cb
    );

    void unmarshall_interface_set_transit_delay(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetTransitDelayCB		cb
    );

    void unmarshall_interface_get_transit_delay(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetTransitDelayCB		cb
    );

    void unmarshall_interface_set_retransmit_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetRetransmitIntervalCB		cb
    );

    void unmarshall_interface_get_retransmit_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetRetransmitIntervalCB		cb
    );

    void unmarshall_interface_set_router_dead_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetRouterDeadIntervalCB		cb
    );

    void unmarshall_interface_get_router_dead_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetRouterDeadIntervalCB		cb
    );

    void unmarshall_interface_set_poll_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetPollIntervalCB		cb
    );

    void unmarshall_interface_get_poll_interval(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetPollIntervalCB		cb
    );

    void unmarshall_interface_set_authentication(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetAuthenticationCB		cb
    );

    void unmarshall_interface_get_authentication(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetAuthenticationCB		cb
    );

    void unmarshall_interface_set_multicast_forwarding(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetMulticastForwardingCB		cb
    );

    void unmarshall_interface_get_multicast_forwarding(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetMulticastForwardingCB		cb
    );

    void unmarshall_interface_set_on_demand(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetOnDemandCB		cb
    );

    void unmarshall_interface_get_on_demand(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetOnDemandCB		cb
    );

    void unmarshall_interface_set_passive(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetPassiveCB		cb
    );

    void unmarshall_interface_get_passive(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetPassiveCB		cb
    );

    void unmarshall_interface_set_igmp(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceSetIgmpCB		cb
    );

    void unmarshall_interface_get_igmp(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetIgmpCB		cb
    );

    void unmarshall_delete_interface(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteInterfaceCB		cb
    );

    void unmarshall_list_interfaces(
	const XrlError&	e,
	XrlArgs*	a,
	ListInterfacesCB		cb
    );

    void unmarshall_interface_add_md5_key(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceAddMd5KeyCB		cb
    );

    void unmarshall_interface_get_md5_key(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceGetMd5KeyCB		cb
    );

    void unmarshall_interface_delete_md5_key(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceDeleteMd5KeyCB		cb
    );

    void unmarshall_interface_list_md5_keys(
	const XrlError&	e,
	XrlArgs*	a,
	InterfaceListMd5KeysCB		cb
    );

    void unmarshall_add_neighbor(
	const XrlError&	e,
	XrlArgs*	a,
	AddNeighborCB		cb
    );

    void unmarshall_get_neighbor(
	const XrlError&	e,
	XrlArgs*	a,
	GetNeighborCB		cb
    );

    void unmarshall_delete_neighbor(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteNeighborCB		cb
    );

    void unmarshall_list_neighbors(
	const XrlError&	e,
	XrlArgs*	a,
	ListNeighborsCB		cb
    );

};

#endif /* __XRL_INTERFACES_OSPF_XIF_HH__ */
