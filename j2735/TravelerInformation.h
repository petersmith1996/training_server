/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_TravelerInformation_H_
#define	_TravelerInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DSRC_MsgCount.h"
#include "MinuteOfTheYear.h"
#include "UniqueMSGID.h"
#include "URL-Base.h"
#include "TravelerDataFrameList.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Reg_BasicSafetyMessage;

/* TravelerInformation */
typedef struct TravelerInformation {
	DSRC_MsgCount_t	 msgCnt;
	MinuteOfTheYear_t	*timeStamp;	/* OPTIONAL */
	UniqueMSGID_t	*packetID;	/* OPTIONAL */
	URL_Base_t	*urlB;	/* OPTIONAL */
	TravelerDataFrameList_t	 dataFrames;
	struct TravelerInformation__regional {
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
} TravelerInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TravelerInformation;
extern asn_SEQUENCE_specifics_t asn_SPC_TravelerInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_TravelerInformation_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _TravelerInformation_H_ */
#include <asn_internal.h>
