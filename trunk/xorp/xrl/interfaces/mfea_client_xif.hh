/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/mfea_client_xif.hh,v 1.14 2004/06/10 22:42:02 hodson Exp $
 */

#ifndef __XRL_INTERFACES_MFEA_CLIENT_XIF_HH__
#define __XRL_INTERFACES_MFEA_CLIENT_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifMfeaClient"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlMfeaClientV0p1Client {
public:
    XrlMfeaClientV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlMfeaClientV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr NewVifCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add a new vif.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the new vif.
     *
     *  @param vif_index the index of the new vif.
     */
    bool send_new_vif(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const NewVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteVifCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete an existing vif.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to delete.
     */
    bool send_delete_vif(
	const char*	target_name,
	const string&	vif_name,
	const DeleteVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddVifAddr4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add an address to a vif.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif.
     *
     *  @param addr the unicast address to add.
     *
     *  @param subnet the subnet address to add.
     *
     *  @param broadcast the broadcast address (when applicable).
     *
     *  @param peer the peer address (when applicable).
     */
    bool send_add_vif_addr4(
	const char*	target_name,
	const string&	vif_name,
	const IPv4&	addr,
	const IPv4Net&	subnet,
	const IPv4&	broadcast,
	const IPv4&	peer,
	const AddVifAddr4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddVifAddr6CB;

    bool send_add_vif_addr6(
	const char*	target_name,
	const string&	vif_name,
	const IPv6&	addr,
	const IPv6Net&	subnet,
	const IPv6&	broadcast,
	const IPv6&	peer,
	const AddVifAddr6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteVifAddr4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete an address from a vif.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif.
     *
     *  @param addr the unicast address to delete.
     */
    bool send_delete_vif_addr4(
	const char*	target_name,
	const string&	vif_name,
	const IPv4&	addr,
	const DeleteVifAddr4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteVifAddr6CB;

    bool send_delete_vif_addr6(
	const char*	target_name,
	const string&	vif_name,
	const IPv6&	addr,
	const DeleteVifAddr6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifFlagsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set flags to a vif.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif.
     *
     *  @param is_pim_register true if this is a PIM Register vif.
     *
     *  @param is_p2p true if this is a point-to-point vif.
     *
     *  @param is_loopback true if this is a loopback interface.
     *
     *  @param is_multicast true if the vif is multicast-capable.
     *
     *  @param is_broadcast true if the vif is broadcast-capable.
     *
     *  @param is_up true if the vif is UP and running.
     */
    bool send_set_vif_flags(
	const char*	target_name,
	const string&	vif_name,
	const bool&	is_pim_register,
	const bool&	is_p2p,
	const bool&	is_loopback,
	const bool&	is_multicast,
	const bool&	is_broadcast,
	const bool&	is_up,
	const SetVifFlagsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetAllVifsDoneCB;
    /**
     *  Send Xrl intended to:
     *
     *  Complete all transactions with vif information.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_all_vifs_done(
	const char*	target_name,
	const SetAllVifsDoneCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr IsVifSetupCompletedCB;
    /**
     *  Send Xrl intended to:
     *
     *  Test if the vif setup is completed.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_is_vif_setup_completed(
	const char*	target_name,
	const IsVifSetupCompletedCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvProtocolMessage4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Receive a protocol message from the MFEA.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol that sends a message.
     *
     *  @param protocol_id the ID of the protocol that sends a message (both
     *  sides must agree on the particular values).
     *
     *  @param vif_name the name of the vif the message was received on.
     *
     *  @param vif_index the index of the vif the message was received on.
     *
     *  @param source_address the address of the sender.
     *
     *  @param dest_address the destination address.
     *
     *  @param ip_ttl the TTL of the received IP packet. If it has a negative
     *  value, it should be ignored.
     *
     *  @param ip_tos the TOS of the received IP packet. If it has a negative
     *  value, it should be ignored.
     *
     *  @param is_router_alert if true, the IP Router Alert option in the IP
     *  packet was set (when applicable).
     *
     *  @param protocol_message the protocol message.
     */
    bool send_recv_protocol_message4(
	const char*	target_name,
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
	const vector<uint8_t>&	protocol_message,
	const RecvProtocolMessage4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvProtocolMessage6CB;

    bool send_recv_protocol_message6(
	const char*	target_name,
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
	const vector<uint8_t>&	protocol_message,
	const RecvProtocolMessage6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvKernelSignalMessage4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Receive a kernel signal message from the MFEA.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol that sends a message.
     *
     *  @param protocol_id the ID of the protocol that sends a message (both
     *  sides must agree on the particular values).
     *
     *  @param message_type the type of the kernel signal message (TODO:
     *  integer for now: the particular types are well-known by both sides).
     *
     *  @param vif_name the name of the vif the message was received on.
     *
     *  @param vif_index the index of the vif the message was received on.
     *
     *  @param source_address the address of the sender.
     *
     *  @param dest_address the destination address.
     *
     *  @param protocol_message the protocol message.
     */
    bool send_recv_kernel_signal_message4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const uint32_t&	message_type,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv4&	source_address,
	const IPv4&	dest_address,
	const vector<uint8_t>&	protocol_message,
	const RecvKernelSignalMessage4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvKernelSignalMessage6CB;

    bool send_recv_kernel_signal_message6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const uint32_t&	message_type,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const IPv6&	source_address,
	const IPv6&	dest_address,
	const vector<uint8_t>&	protocol_message,
	const RecvKernelSignalMessage6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvDataflowSignal4CB;
    /**
     *  Send Xrl intended to:
     *
     *  A signal that a dataflow-related pre-condition is true.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param source_address the source address of the dataflow.
     *
     *  @param group_address the group address of the dataflow.
     *
     *  @param threshold_interval_sec the number of seconds in the interval
     *  requested for measurement.
     *
     *  @param threshold_interval_usec the number of microseconds in the
     *  interval requested for measurement.
     *
     *  @param measured_interval_sec the number of seconds in the last measured
     *  interval that has triggered the signal.
     *
     *  @param measured_interval_usec the number of microseconds in the last
     *  measured interval that has triggered the signal.
     *
     *  @param threshold_packets the threshold value to trigger a signal (in
     *  number of packets).
     *
     *  @param threshold_bytes the threshold value to trigger a signal (in
     *  bytes).
     *
     *  @param measured_packets the number of packets measured within the
     *  measured interval.
     *
     *  @param measured_bytes the number of bytes measured within the measured
     *  interval.
     *
     *  @param is_threshold_in_packets if true, threshold_packets is valid.
     *
     *  @param is_threshold_in_bytes if true, threshold_bytes is valid.
     *
     *  @param is_geq_upcall if true, the operation for comparison is ">=".
     *
     *  @param is_leq_upcall if true, the operation for comparison is "<=".
     */
    bool send_recv_dataflow_signal4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const IPv4&	source_address,
	const IPv4&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	measured_interval_sec,
	const uint32_t&	measured_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const uint32_t&	measured_packets,
	const uint32_t&	measured_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const RecvDataflowSignal4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RecvDataflowSignal6CB;

    bool send_recv_dataflow_signal6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const IPv6&	source_address,
	const IPv6&	group_address,
	const uint32_t&	threshold_interval_sec,
	const uint32_t&	threshold_interval_usec,
	const uint32_t&	measured_interval_sec,
	const uint32_t&	measured_interval_usec,
	const uint32_t&	threshold_packets,
	const uint32_t&	threshold_bytes,
	const uint32_t&	measured_packets,
	const uint32_t&	measured_bytes,
	const bool&	is_threshold_in_packets,
	const bool&	is_threshold_in_bytes,
	const bool&	is_geq_upcall,
	const bool&	is_leq_upcall,
	const RecvDataflowSignal6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_new_vif(
	const XrlError&	e,
	XrlArgs*	a,
	NewVifCB		cb
    );

    void unmarshall_delete_vif(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVifCB		cb
    );

    void unmarshall_add_vif_addr4(
	const XrlError&	e,
	XrlArgs*	a,
	AddVifAddr4CB		cb
    );

    void unmarshall_add_vif_addr6(
	const XrlError&	e,
	XrlArgs*	a,
	AddVifAddr6CB		cb
    );

    void unmarshall_delete_vif_addr4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVifAddr4CB		cb
    );

    void unmarshall_delete_vif_addr6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVifAddr6CB		cb
    );

    void unmarshall_set_vif_flags(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifFlagsCB		cb
    );

    void unmarshall_set_all_vifs_done(
	const XrlError&	e,
	XrlArgs*	a,
	SetAllVifsDoneCB		cb
    );

    void unmarshall_is_vif_setup_completed(
	const XrlError&	e,
	XrlArgs*	a,
	IsVifSetupCompletedCB		cb
    );

    void unmarshall_recv_protocol_message4(
	const XrlError&	e,
	XrlArgs*	a,
	RecvProtocolMessage4CB		cb
    );

    void unmarshall_recv_protocol_message6(
	const XrlError&	e,
	XrlArgs*	a,
	RecvProtocolMessage6CB		cb
    );

    void unmarshall_recv_kernel_signal_message4(
	const XrlError&	e,
	XrlArgs*	a,
	RecvKernelSignalMessage4CB		cb
    );

    void unmarshall_recv_kernel_signal_message6(
	const XrlError&	e,
	XrlArgs*	a,
	RecvKernelSignalMessage6CB		cb
    );

    void unmarshall_recv_dataflow_signal4(
	const XrlError&	e,
	XrlArgs*	a,
	RecvDataflowSignal4CB		cb
    );

    void unmarshall_recv_dataflow_signal6(
	const XrlError&	e,
	XrlArgs*	a,
	RecvDataflowSignal6CB		cb
    );

};

#endif /* __XRL_INTERFACES_MFEA_CLIENT_XIF_HH__ */
