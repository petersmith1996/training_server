/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITIS"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#include "ResponderGroupAffected.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ResponderGroupAffected_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_ResponderGroupAffected_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  0,  13 }	/* (0..13,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_ResponderGroupAffected_value2enum_1[] = {
	{ 9729,	23,	"emergency-vehicle-units" },
	{ 9730,	29,	"federal-law-enforcement-units" },
	{ 9731,	18,	"state-police-units" },
	{ 9732,	19,	"county-police-units" },
	{ 9733,	18,	"local-police-units" },
	{ 9734,	15,	"ambulance-units" },
	{ 9735,	12,	"rescue-units" },
	{ 9736,	10,	"fire-units" },
	{ 9737,	12,	"hAZMAT-units" },
	{ 9738,	14,	"light-tow-unit" },
	{ 9739,	14,	"heavy-tow-unit" },
	{ 9740,	23,	"freeway-service-patrols" },
	{ 9741,	29,	"transportation-response-units" },
	{ 9742,	33,	"private-contractor-response-units" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_ResponderGroupAffected_enum2value_1[] = {
	5,	/* ambulance-units(9734) */
	3,	/* county-police-units(9732) */
	0,	/* emergency-vehicle-units(9729) */
	1,	/* federal-law-enforcement-units(9730) */
	7,	/* fire-units(9736) */
	11,	/* freeway-service-patrols(9740) */
	8,	/* hAZMAT-units(9737) */
	10,	/* heavy-tow-unit(9739) */
	9,	/* light-tow-unit(9738) */
	4,	/* local-police-units(9733) */
	13,	/* private-contractor-response-units(9742) */
	6,	/* rescue-units(9735) */
	2,	/* state-police-units(9731) */
	12	/* transportation-response-units(9741) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_ResponderGroupAffected_specs_1 = {
	asn_MAP_ResponderGroupAffected_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_ResponderGroupAffected_enum2value_1,	/* N => "tag"; sorted by N */
	14,	/* Number of elements in the maps */
	15,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ResponderGroupAffected_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ResponderGroupAffected = {
	"ResponderGroupAffected",
	"ResponderGroupAffected",
	&asn_OP_NativeEnumerated,
	asn_DEF_ResponderGroupAffected_tags_1,
	sizeof(asn_DEF_ResponderGroupAffected_tags_1)
		/sizeof(asn_DEF_ResponderGroupAffected_tags_1[0]), /* 1 */
	asn_DEF_ResponderGroupAffected_tags_1,	/* Same as above */
	sizeof(asn_DEF_ResponderGroupAffected_tags_1)
		/sizeof(asn_DEF_ResponderGroupAffected_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ResponderGroupAffected_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ResponderGroupAffected_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ResponderGroupAffected_specs_1	/* Additional specs */
};

