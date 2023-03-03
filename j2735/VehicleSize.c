/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#include "VehicleSize.h"

asn_TYPE_member_t asn_MBR_VehicleSize_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VehicleSize, width),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleWidth,
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
		"width"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VehicleSize, length),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleLength,
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
		"length"
		},
};
static const ber_tlv_tag_t asn_DEF_VehicleSize_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_VehicleSize_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* width */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* length */
};
asn_SEQUENCE_specifics_t asn_SPC_VehicleSize_specs_1 = {
	sizeof(struct VehicleSize),
	offsetof(struct VehicleSize, _asn_ctx),
	asn_MAP_VehicleSize_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_VehicleSize = {
	"VehicleSize",
	"VehicleSize",
	&asn_OP_SEQUENCE,
	asn_DEF_VehicleSize_tags_1,
	sizeof(asn_DEF_VehicleSize_tags_1)
		/sizeof(asn_DEF_VehicleSize_tags_1[0]), /* 1 */
	asn_DEF_VehicleSize_tags_1,	/* Same as above */
	sizeof(asn_DEF_VehicleSize_tags_1)
		/sizeof(asn_DEF_VehicleSize_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_VehicleSize_1,
	2,	/* Elements count */
	&asn_SPC_VehicleSize_specs_1	/* Additional specs */
};

