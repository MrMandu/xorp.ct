/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_fib_xif.cc,v 1.11 2007/02/16 22:47:36 pavlin Exp $"

#include "fea_fib_xif.hh"

bool
XrlFeaFibV0p1Client::send_add_fib_client4(
	const char*	dst_xrl_target_name,
	const string&	client_target_name,
	const bool&	send_updates,
	const bool&	send_resolves,
	const AddFibClient4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_fib/0.1/add_fib_client4");
    x.args().add("client_target_name", client_target_name);
    x.args().add("send_updates", send_updates);
    x.args().add("send_resolves", send_resolves);
    return _sender->send(x, callback(this, &XrlFeaFibV0p1Client::unmarshall_add_fib_client4, cb));
}


/* Unmarshall add_fib_client4 */
void
XrlFeaFibV0p1Client::unmarshall_add_fib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	AddFibClient4CB		cb
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
XrlFeaFibV0p1Client::send_add_fib_client6(
	const char*	dst_xrl_target_name,
	const string&	client_target_name,
	const bool&	send_updates,
	const bool&	send_resolves,
	const AddFibClient6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_fib/0.1/add_fib_client6");
    x.args().add("client_target_name", client_target_name);
    x.args().add("send_updates", send_updates);
    x.args().add("send_resolves", send_resolves);
    return _sender->send(x, callback(this, &XrlFeaFibV0p1Client::unmarshall_add_fib_client6, cb));
}


/* Unmarshall add_fib_client6 */
void
XrlFeaFibV0p1Client::unmarshall_add_fib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	AddFibClient6CB		cb
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
XrlFeaFibV0p1Client::send_delete_fib_client4(
	const char*	dst_xrl_target_name,
	const string&	client_target_name,
	const DeleteFibClient4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_fib/0.1/delete_fib_client4");
    x.args().add("client_target_name", client_target_name);
    return _sender->send(x, callback(this, &XrlFeaFibV0p1Client::unmarshall_delete_fib_client4, cb));
}


/* Unmarshall delete_fib_client4 */
void
XrlFeaFibV0p1Client::unmarshall_delete_fib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteFibClient4CB		cb
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
XrlFeaFibV0p1Client::send_delete_fib_client6(
	const char*	dst_xrl_target_name,
	const string&	client_target_name,
	const DeleteFibClient6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_fib/0.1/delete_fib_client6");
    x.args().add("client_target_name", client_target_name);
    return _sender->send(x, callback(this, &XrlFeaFibV0p1Client::unmarshall_delete_fib_client6, cb));
}


/* Unmarshall delete_fib_client6 */
void
XrlFeaFibV0p1Client::unmarshall_delete_fib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteFibClient6CB		cb
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
