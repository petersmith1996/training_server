/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpB"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_NodeOffsetPointXY_addGrpB_H_
#define	_NodeOffsetPointXY_addGrpB_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Node-LLdms-48b.h"
#include "Node-LLdms-80b.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NodeOffsetPointXY_addGrpB_PR {
	NodeOffsetPointXY_addGrpB_PR_NOTHING,	/* No components present */
	NodeOffsetPointXY_addGrpB_PR_posA,
	NodeOffsetPointXY_addGrpB_PR_posB
	/* Extensions may appear below */
	
} NodeOffsetPointXY_addGrpB_PR;

/* NodeOffsetPointXY-addGrpB */
typedef struct NodeOffsetPointXY_addGrpB {
	NodeOffsetPointXY_addGrpB_PR present;
	union NodeOffsetPointXY_addGrpB_u {
		Node_LLdms_48b_t	 posA;
		Node_LLdms_80b_t	 posB;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NodeOffsetPointXY_addGrpB_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NodeOffsetPointXY_addGrpB;
extern asn_CHOICE_specifics_t asn_SPC_NodeOffsetPointXY_addGrpB_specs_1;
extern asn_TYPE_member_t asn_MBR_NodeOffsetPointXY_addGrpB_1[2];
extern asn_per_constraints_t asn_PER_type_NodeOffsetPointXY_addGrpB_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NodeOffsetPointXY_addGrpB_H_ */
#include <asn_internal.h>
