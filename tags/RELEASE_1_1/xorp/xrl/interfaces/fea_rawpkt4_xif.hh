/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_rawpkt4_xif.hh,v 1.1 2004/11/29 00:32:07 bms Exp $
 */

#ifndef __XRL_INTERFACES_FEA_RAWPKT4_XIF_HH__
#define __XRL_INTERFACES_FEA_RAWPKT4_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaRawpkt4"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlRawPacket4V0p1Client {
public:
    XrlRawPacket4V0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlRawPacket4V0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send a packet on a raw socket.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_send(
	const char*	target_name,
	const IPv4&	src_address,
	const IPv4&	dst_address,
	const string&	vif_name,
	const uint32_t&	proto,
	const uint32_t&	ttl,
	const uint32_t&	tos,
	const vector<uint8_t>&	options,
	const vector<uint8_t>&	payload,
	const SendCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendRawCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send raw packet. Checksum is computed and applied before transmission.
     *  All the fields within the IPv4 header must be in network order.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_send_raw(
	const char*	target_name,
	const string&	vif_name,
	const vector<uint8_t>&	packet,
	const SendRawCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterVifReceiverCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register to receive packets. The receiver is expected to support
     *  raw_socket_client/0.1 interface.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_register_vif_receiver(
	const char*	target_name,
	const string&	router_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	proto,
	const RegisterVifReceiverCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterVifReceiverCB;
    /**
     *  Send Xrl intended to:
     *
     *  Unregister stop receiving packets.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param proto Protocol number that the receiver is interested in.
     */
    bool send_unregister_vif_receiver(
	const char*	target_name,
	const string&	router_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	proto,
	const UnregisterVifReceiverCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_send(
	const XrlError&	e,
	XrlArgs*	a,
	SendCB		cb
    );

    void unmarshall_send_raw(
	const XrlError&	e,
	XrlArgs*	a,
	SendRawCB		cb
    );

    void unmarshall_register_vif_receiver(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterVifReceiverCB		cb
    );

    void unmarshall_unregister_vif_receiver(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterVifReceiverCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_RAWPKT4_XIF_HH__ */
