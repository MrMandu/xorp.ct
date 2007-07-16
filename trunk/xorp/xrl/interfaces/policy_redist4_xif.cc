/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/policy_redist4_xif.cc,v 1.7 2007/02/16 22:47:41 pavlin Exp $"

#include "policy_redist4_xif.hh"

bool
XrlPolicyRedist4V0p1Client::send_add_route4(
	const char*	dst_xrl_target_name,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags,
	const AddRoute4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "policy_redist4/0.1/add_route4");
    x.args().add("network", network);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    x.args().add("policytags", policytags);
    return _sender->send(x, callback(this, &XrlPolicyRedist4V0p1Client::unmarshall_add_route4, cb));
}


/* Unmarshall add_route4 */
void
XrlPolicyRedist4V0p1Client::unmarshall_add_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlPolicyRedist4V0p1Client::send_delete_route4(
	const char*	dst_xrl_target_name,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteRoute4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "policy_redist4/0.1/delete_route4");
    x.args().add("network", network);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlPolicyRedist4V0p1Client::unmarshall_delete_route4, cb));
}


/* Unmarshall delete_route4 */
void
XrlPolicyRedist4V0p1Client::unmarshall_delete_route4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
