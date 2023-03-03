/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_MovementEvent_H_
#define	_MovementEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MovementPhaseState.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct TimeChangeDetails;
struct AdvisorySpeedList;
struct Reg_BasicSafetyMessage;

/* MovementEvent */
typedef struct MovementEvent {
	MovementPhaseState_t	 eventState;
	struct TimeChangeDetails	*timing;	/* OPTIONAL */
	struct AdvisorySpeedList	*speeds;	/* OPTIONAL */
	struct MovementEvent__regional {
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
} MovementEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MovementEvent;
extern asn_SEQUENCE_specifics_t asn_SPC_MovementEvent_specs_1;
extern asn_TYPE_member_t asn_MBR_MovementEvent_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "TimeChangeDetails.h"
#include "AdvisorySpeedList.h"
#include "RegionalExtension.h"

#endif	/* _MovementEvent_H_ */
#include <asn_internal.h>
