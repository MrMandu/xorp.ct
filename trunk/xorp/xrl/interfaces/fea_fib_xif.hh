/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP$
 */

#ifndef __XRL_INTERFACES_FEA_FIB_XIF_HH__
#define __XRL_INTERFACES_FEA_FIB_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaFib"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFeaFibV0p1Client {
public:
    XrlFeaFibV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFeaFibV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddFibClient4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add a FIB client.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param target_name the target name of the FIB client to add.
     */
    bool send_add_fib_client4(
	const char*	target_name,
	const string&	target_name,
	const AddFibClient4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddFibClient6CB;

    bool send_add_fib_client6(
	const char*	target_name,
	const string&	target_name,
	const AddFibClient6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteFibClient4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete a FIB client.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param target_name the target name of the FIB client to delete.
     */
    bool send_delete_fib_client4(
	const char*	target_name,
	const string&	target_name,
	const DeleteFibClient4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteFibClient6CB;

    bool send_delete_fib_client6(
	const char*	target_name,
	const string&	target_name,
	const DeleteFibClient6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_add_fib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	AddFibClient4CB		cb
    );

    void unmarshall_add_fib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	AddFibClient6CB		cb
    );

    void unmarshall_delete_fib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteFibClient4CB		cb
    );

    void unmarshall_delete_fib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteFibClient6CB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_FIB_XIF_HH__ */
