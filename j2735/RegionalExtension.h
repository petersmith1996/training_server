/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_RegionalExtension_H_
#define	_RegionalExtension_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RegionId.h"
#include <ANY.h>
#include <asn_ioc.h>
#include <OPEN_TYPE.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Reg_BasicSafetyMessage__regExtValue_PR {
	Reg_BasicSafetyMessage__regExtValue_PR_NOTHING	/* No components present */
	
} Reg_BasicSafetyMessage__regExtValue_PR;

/* RegionalExtension */
typedef struct Reg_BasicSafetyMessage {
	RegionId_t	 regionId;
	struct Reg_BasicSafetyMessage__regExtValue {
		Reg_BasicSafetyMessage__regExtValue_PR present;
		union Reg_BasicSafetyMessage__regExtValue_u {
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} regExtValue;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Reg_BasicSafetyMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Reg_BasicSafetyMessage;
extern asn_SEQUENCE_specifics_t asn_SPC_Reg_BasicSafetyMessage_specs_1;
extern asn_TYPE_member_t asn_MBR_Reg_BasicSafetyMessage_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RegionalExtension_H_ */
#include <asn_internal.h>