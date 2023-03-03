/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_YawRate_H_
#define	_YawRate_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* YawRate */
typedef long	 YawRate_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_YawRate_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_YawRate;
asn_struct_free_f YawRate_free;
asn_struct_print_f YawRate_print;
asn_constr_check_f YawRate_constraint;
ber_type_decoder_f YawRate_decode_ber;
der_type_encoder_f YawRate_encode_der;
xer_type_decoder_f YawRate_decode_xer;
xer_type_encoder_f YawRate_encode_xer;
jer_type_encoder_f YawRate_encode_jer;
oer_type_decoder_f YawRate_decode_oer;
oer_type_encoder_f YawRate_encode_oer;
per_type_decoder_f YawRate_decode_uper;
per_type_encoder_f YawRate_encode_uper;
per_type_decoder_f YawRate_decode_aper;
per_type_encoder_f YawRate_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _YawRate_H_ */
#include <asn_internal.h>
