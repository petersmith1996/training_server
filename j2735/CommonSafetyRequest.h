/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_CommonSafetyRequest_H_
#define	_CommonSafetyRequest_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MinuteOfTheYear.h"
#include "DSRC_MsgCount.h"
#include "TemporaryID.h"
#include "RequestedItemList.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Reg_BasicSafetyMessage;

/* CommonSafetyRequest */
typedef struct CommonSafetyRequest {
	MinuteOfTheYear_t	*timeStamp;	/* OPTIONAL */
	DSRC_MsgCount_t	*msgCnt;	/* OPTIONAL */
	TemporaryID_t	*id;	/* OPTIONAL */
	RequestedItemList_t	 requests;
	struct CommonSafetyRequest__regional {
		A_SEQUENCE_OF(struct Reg_BasicSafetyMessage) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *regional;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CommonSafetyRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CommonSafetyRequest;
extern asn_SEQUENCE_specifics_t asn_SPC_CommonSafetyRequest_specs_1;
extern asn_TYPE_member_t asn_MBR_CommonSafetyRequest_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _CommonSafetyRequest_H_ */
#include <asn_internal.h>
