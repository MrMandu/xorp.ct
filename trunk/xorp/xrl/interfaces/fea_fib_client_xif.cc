/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "fea_fib_client_xif.hh"

bool
XrlFeaFibClientV0p1Client::send_add_route4(
	const char*	the_tgt,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route,
	const AddRoute4CB&	cb
)
{
    Xrl x(the_tgt, "fea_fib_client/0.1/add_route4");
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    x.args().add("admin_distance", admin_distance);
    x.args().add("protocol_origin", protocol_origin);
    x.args().add("xorp_route", xorp_route);
    return _sender->send(x, callback(this, &XrlFeaFibClientV0p1Client::unmarshall_add_route4, cb));
}


/* Unmarshall add_route4 */
void
XrlFeaFibClientV0p1Client::unmarshall_add_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaFibClientV0p1Client::send_add_route6(
	const char*	the_tgt,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	admin_distance,
	const string&	protocol_origin,
	const bool&	xorp_route,
	const AddRoute6CB&	cb
)
{
    Xrl x(the_tgt, "fea_fib_client/0.1/add_route6");
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    x.args().add("admin_distance", admin_distance);
    x.args().add("protocol_origin", protocol_origin);
    x.args().add("xorp_route", xorp_route);
    return _sender->send(x, callback(this, &XrlFeaFibClientV0p1Client::unmarshall_add_route6, cb));
}


/* Unmarshall add_route6 */
void
XrlFeaFibClientV0p1Client::unmarshall_add_route6(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaFibClientV0p1Client::send_delete_route4(
	const char*	the_tgt,
	const IPv4Net&	network,
	const DeleteRoute4CB&	cb
)
{
    Xrl x(the_tgt, "fea_fib_client/0.1/delete_route4");
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlFeaFibClientV0p1Client::unmarshall_delete_route4, cb));
}


/* Unmarshall delete_route4 */
void
XrlFeaFibClientV0p1Client::unmarshall_delete_route4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlFeaFibClientV0p1Client::send_delete_route6(
	const char*	the_tgt,
	const IPv6Net&	network,
	const DeleteRoute6CB&	cb
)
{
    Xrl x(the_tgt, "fea_fib_client/0.1/delete_route6");
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlFeaFibClientV0p1Client::unmarshall_delete_route6, cb));
}


/* Unmarshall delete_route6 */
void
XrlFeaFibClientV0p1Client::unmarshall_delete_route6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
