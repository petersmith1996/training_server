/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#include "RTCMheader.h"

asn_TYPE_member_t asn_MBR_RTCMheader_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RTCMheader, status),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GNSSstatus,
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
		"status"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RTCMheader, offsetSet),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AntennaOffsetSet,
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
		"offsetSet"
		},
};
static const ber_tlv_tag_t asn_DEF_RTCMheader_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RTCMheader_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* status */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* offsetSet */
};
asn_SEQUENCE_specifics_t asn_SPC_RTCMheader_specs_1 = {
	sizeof(struct RTCMheader),
	offsetof(struct RTCMheader, _asn_ctx),
	asn_MAP_RTCMheader_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RTCMheader = {
	"RTCMheader",
	"RTCMheader",
	&asn_OP_SEQUENCE,
	asn_DEF_RTCMheader_tags_1,
	sizeof(asn_DEF_RTCMheader_tags_1)
		/sizeof(asn_DEF_RTCMheader_tags_1[0]), /* 1 */
	asn_DEF_RTCMheader_tags_1,	/* Same as above */
	sizeof(asn_DEF_RTCMheader_tags_1)
		/sizeof(asn_DEF_RTCMheader_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_RTCMheader_1,
	2,	/* Elements count */
	&asn_SPC_RTCMheader_specs_1	/* Additional specs */
};
