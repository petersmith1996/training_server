/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#include "SignalHeadLocation.h"

asn_TYPE_member_t asn_MBR_SignalHeadLocation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SignalHeadLocation, node),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NodeOffsetPointXY,
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
		"node"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SignalHeadLocation, signalGroupID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SignalGroupID,
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
		"signalGroupID"
		},
};
static const ber_tlv_tag_t asn_DEF_SignalHeadLocation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SignalHeadLocation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* node */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* signalGroupID */
};
asn_SEQUENCE_specifics_t asn_SPC_SignalHeadLocation_specs_1 = {
	sizeof(struct SignalHeadLocation),
	offsetof(struct SignalHeadLocation, _asn_ctx),
	asn_MAP_SignalHeadLocation_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SignalHeadLocation = {
	"SignalHeadLocation",
	"SignalHeadLocation",
	&asn_OP_SEQUENCE,
	asn_DEF_SignalHeadLocation_tags_1,
	sizeof(asn_DEF_SignalHeadLocation_tags_1)
		/sizeof(asn_DEF_SignalHeadLocation_tags_1[0]), /* 1 */
	asn_DEF_SignalHeadLocation_tags_1,	/* Same as above */
	sizeof(asn_DEF_SignalHeadLocation_tags_1)
		/sizeof(asn_DEF_SignalHeadLocation_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_SignalHeadLocation_1,
	2,	/* Elements count */
	&asn_SPC_SignalHeadLocation_specs_1	/* Additional specs */
};

