/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_Confidence_H_
#define	_Confidence_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Confidence */
typedef long	 Confidence_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Confidence_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Confidence;
asn_struct_free_f Confidence_free;
asn_struct_print_f Confidence_print;
asn_constr_check_f Confidence_constraint;
ber_type_decoder_f Confidence_decode_ber;
der_type_encoder_f Confidence_encode_der;
xer_type_decoder_f Confidence_decode_xer;
xer_type_encoder_f Confidence_encode_xer;
jer_type_encoder_f Confidence_encode_jer;
oer_type_decoder_f Confidence_decode_oer;
oer_type_encoder_f Confidence_encode_oer;
per_type_decoder_f Confidence_decode_uper;
per_type_encoder_f Confidence_encode_uper;
per_type_decoder_f Confidence_decode_aper;
per_type_encoder_f Confidence_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Confidence_H_ */
#include <asn_internal.h>
