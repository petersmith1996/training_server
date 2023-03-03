/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_LaneDataAttribute_H_
#define	_LaneDataAttribute_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DeltaAngle.h"
#include "RoadwayCrownAngle.h"
#include "MergeDivergeNodeAngle.h"
#include "SpeedLimitList.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LaneDataAttribute_PR {
	LaneDataAttribute_PR_NOTHING,	/* No components present */
	LaneDataAttribute_PR_pathEndPointAngle,
	LaneDataAttribute_PR_laneCrownPointCenter,
	LaneDataAttribute_PR_laneCrownPointLeft,
	LaneDataAttribute_PR_laneCrownPointRight,
	LaneDataAttribute_PR_laneAngle,
	LaneDataAttribute_PR_speedLimits,
	LaneDataAttribute_PR_regional
	/* Extensions may appear below */
	
} LaneDataAttribute_PR;

/* Forward declarations */
struct Reg_BasicSafetyMessage;

/* LaneDataAttribute */
typedef struct LaneDataAttribute {
	LaneDataAttribute_PR present;
	union LaneDataAttribute_u {
		DeltaAngle_t	 pathEndPointAngle;
		RoadwayCrownAngle_t	 laneCrownPointCenter;
		RoadwayCrownAngle_t	 laneCrownPointLeft;
		RoadwayCrownAngle_t	 laneCrownPointRight;
		MergeDivergeNodeAngle_t	 laneAngle;
		SpeedLimitList_t	 speedLimits;
		struct LaneDataAttribute__regional {
			A_SEQUENCE_OF(struct Reg_BasicSafetyMessage) list;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} regional;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LaneDataAttribute_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LaneDataAttribute;
extern asn_CHOICE_specifics_t asn_SPC_LaneDataAttribute_specs_1;
extern asn_TYPE_member_t asn_MBR_LaneDataAttribute_1[7];
extern asn_per_constraints_t asn_PER_type_LaneDataAttribute_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _LaneDataAttribute_H_ */
#include <asn_internal.h>
