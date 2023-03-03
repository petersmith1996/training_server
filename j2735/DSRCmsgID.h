/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../J2735_201603.asn1"
 * 	`asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -pdu=auto`
 */

#ifndef	_DSRCmsgID_H_
#define	_DSRCmsgID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DSRCmsgID */
typedef long	 DSRCmsgID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DSRCmsgID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DSRCmsgID;
asn_struct_free_f DSRCmsgID_free;
asn_struct_print_f DSRCmsgID_print;
asn_constr_check_f DSRCmsgID_constraint;
ber_type_decoder_f DSRCmsgID_decode_ber;
der_type_encoder_f DSRCmsgID_encode_der;
xer_type_decoder_f DSRCmsgID_decode_xer;
xer_type_encoder_f DSRCmsgID_encode_xer;
jer_type_encoder_f DSRCmsgID_encode_jer;
oer_type_decoder_f DSRCmsgID_decode_oer;
oer_type_encoder_f DSRCmsgID_encode_oer;
per_type_decoder_f DSRCmsgID_decode_uper;
per_type_encoder_f DSRCmsgID_encode_uper;
per_type_decoder_f DSRCmsgID_decode_aper;
per_type_encoder_f DSRCmsgID_encode_aper;
#define DSRCmsgID_reservedMessageId_D	((DSRCmsgID_t)0)
#define DSRCmsgID_alaCarteMessage_D	((DSRCmsgID_t)1)
#define DSRCmsgID_basicSafetyMessage_D	((DSRCmsgID_t)2)
#define DSRCmsgID_basicSafetyMessageVerbose_D	((DSRCmsgID_t)3)
#define DSRCmsgID_commonSafetyRequest_D	((DSRCmsgID_t)4)
#define DSRCmsgID_emergencyVehicleAlert_D	((DSRCmsgID_t)5)
#define DSRCmsgID_intersectionCollision_D	((DSRCmsgID_t)6)
#define DSRCmsgID_mapData_D	((DSRCmsgID_t)7)
#define DSRCmsgID_nmeaCorrections_D	((DSRCmsgID_t)8)
#define DSRCmsgID_probeDataManagement_D	((DSRCmsgID_t)9)
#define DSRCmsgID_probeVehicleData_D	((DSRCmsgID_t)10)
#define DSRCmsgID_roadSideAlert_D	((DSRCmsgID_t)11)
#define DSRCmsgID_rtcmCorrections_D	((DSRCmsgID_t)12)
#define DSRCmsgID_signalPhaseAndTimingMessage_D	((DSRCmsgID_t)13)
#define DSRCmsgID_signalRequestMessage_D	((DSRCmsgID_t)14)
#define DSRCmsgID_signalStatusMessage_D	((DSRCmsgID_t)15)
#define DSRCmsgID_travelerInformation_D	((DSRCmsgID_t)16)
#define DSRCmsgID_uperFrame_D	((DSRCmsgID_t)17)
#define DSRCmsgID_mapData	((DSRCmsgID_t)18)
#define DSRCmsgID_signalPhaseAndTimingMessage	((DSRCmsgID_t)19)
#define DSRCmsgID_basicSafetyMessage	((DSRCmsgID_t)20)
#define DSRCmsgID_commonSafetyRequest	((DSRCmsgID_t)21)
#define DSRCmsgID_emergencyVehicleAlert	((DSRCmsgID_t)22)
#define DSRCmsgID_intersectionCollision	((DSRCmsgID_t)23)
#define DSRCmsgID_nmeaCorrections	((DSRCmsgID_t)24)
#define DSRCmsgID_probeDataManagement	((DSRCmsgID_t)25)
#define DSRCmsgID_probeVehicleData	((DSRCmsgID_t)26)
#define DSRCmsgID_roadSideAlert	((DSRCmsgID_t)27)
#define DSRCmsgID_rtcmCorrections	((DSRCmsgID_t)28)
#define DSRCmsgID_signalRequestMessage	((DSRCmsgID_t)29)
#define DSRCmsgID_signalStatusMessage	((DSRCmsgID_t)30)
#define DSRCmsgID_travelerInformation	((DSRCmsgID_t)31)
#define DSRCmsgID_personalSafetyMessage	((DSRCmsgID_t)32)
#define DSRCmsgID_testMessage00	((DSRCmsgID_t)240)
#define DSRCmsgID_testMessage01	((DSRCmsgID_t)241)
#define DSRCmsgID_testMessage02	((DSRCmsgID_t)242)
#define DSRCmsgID_testMessage03	((DSRCmsgID_t)243)
#define DSRCmsgID_testMessage04	((DSRCmsgID_t)244)
#define DSRCmsgID_testMessage05	((DSRCmsgID_t)245)
#define DSRCmsgID_testMessage06	((DSRCmsgID_t)246)
#define DSRCmsgID_testMessage07	((DSRCmsgID_t)247)
#define DSRCmsgID_testMessage08	((DSRCmsgID_t)248)
#define DSRCmsgID_testMessage09	((DSRCmsgID_t)249)
#define DSRCmsgID_testMessage10	((DSRCmsgID_t)250)
#define DSRCmsgID_testMessage11	((DSRCmsgID_t)251)
#define DSRCmsgID_testMessage12	((DSRCmsgID_t)252)
#define DSRCmsgID_testMessage13	((DSRCmsgID_t)253)
#define DSRCmsgID_testMessage14	((DSRCmsgID_t)254)
#define DSRCmsgID_testMessage15	((DSRCmsgID_t)255)

#ifdef __cplusplus
}
#endif

#endif	/* _DSRCmsgID_H_ */
#include <asn_internal.h>
