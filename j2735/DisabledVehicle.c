/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#include "DisabledVehicle.h"

static int
memb_statusDetails_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 523L && value <= 541L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_statusDetails_constr_2 CC_NOTUSED = {
	{ 2, 1 }	/* (523..541) */,
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_statusDetails_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  523,  541 }	/* (523..541) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_DisabledVehicle_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DisabledVehicle, statusDetails),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ITIScodes,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_statusDetails_constr_2,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_statusDetails_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_statusDetails_constraint_1
		},
		0, 0, /* No default value */
		"statusDetails"
		},
	{ ATF_POINTER, 1, offsetof(struct DisabledVehicle, locationDetails),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GenericLocations,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"locationDetails"
		},
};
static const int asn_MAP_DisabledVehicle_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_DisabledVehicle_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DisabledVehicle_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* statusDetails */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* locationDetails */
};
asn_SEQUENCE_specifics_t asn_SPC_DisabledVehicle_specs_1 = {
	sizeof(struct DisabledVehicle),
	offsetof(struct DisabledVehicle, _asn_ctx),
	asn_MAP_DisabledVehicle_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_DisabledVehicle_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_DisabledVehicle = {
	"DisabledVehicle",
	"DisabledVehicle",
	&asn_OP_SEQUENCE,
	asn_DEF_DisabledVehicle_tags_1,
	sizeof(asn_DEF_DisabledVehicle_tags_1)
		/sizeof(asn_DEF_DisabledVehicle_tags_1[0]), /* 1 */
	asn_DEF_DisabledVehicle_tags_1,	/* Same as above */
	sizeof(asn_DEF_DisabledVehicle_tags_1)
		/sizeof(asn_DEF_DisabledVehicle_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_DisabledVehicle_1,
	2,	/* Elements count */
	&asn_SPC_DisabledVehicle_specs_1	/* Additional specs */
};
