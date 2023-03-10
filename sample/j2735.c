/*
 * UPER Based client application sample code
 *
 * Copyright (c) 2022, CEST
 *
 */

#include "j2735.h"

int opt_debug;

void print_hex(char *data, int len){
    printf("HEX[%d] : ",len);
    for(int i = 0 ; i < len ; i++){
        printf("%02X",(data[i] & 0xFF));
    }
    printf("\n");
}

int encode_j2735_uper(char **dst, MessageFrame_t *src)
{
    int res = -1;
    int buf_len = -1;

    asn_enc_rval_t er = uper_encode(&asn_DEF_MessageFrame, NULL, src, NULL, 0);
    if (er.encoded < 0) {
        fprintf(stderr,
                "It refused to tell buffer size needed for UPER-encoding (rc=%ld)\n",
                er.encoded);
        return -1;
    } else {
        buf_len = ((er.encoded + 7)/8); /* convert length in bits to bytes */
        printf("UPER-encoding encodedMsg PDU requires %d bytes (%ld bits)\n",
               buf_len, er.encoded);
        *dst = (char*)calloc(1, buf_len);
    }

    asn_enc_rval_t ret = uper_encode_to_buffer(&asn_DEF_MessageFrame,
                                               NULL,
                                               src,
                                               *dst, buf_len);
      
    if (ret.encoded > 0)
        return buf_len; //  UPER Encoding Success
    else
    { 
        if (ret.failed_type != NULL)
            printf("encoded error value name = %s\n", ret.failed_type->name);

        return -1; // UPER Encoding failed
    }
}

int decode_j2735_uper_pre(MessageFrame_t *dst, char *src, int size){ 
  
    int res = -1;

    MessageFrame_t *ptrMsg = NULL; 

    asn_dec_rval_t ret = uper_decode(NULL,
                                     &asn_DEF_MessageFrame,
                                     (void **)&dst,
                                     src, size, 0, 0);

    if (ret.code != RC_OK)
        return res;
    
    res = ret.consumed;
 
    //asn_fprint(stdout,&asn_DEF_MessageFrame,dst);

    //parse_decoded_j2735(dst);

    return res;
}

int decode_j2735_uper(MessageFrame_t **dst, char *src, int size){ 
  
    int res = -1;

    MessageFrame_t *ptrMsg = NULL; 

    asn_dec_rval_t ret = uper_decode(NULL,
                                     &asn_DEF_MessageFrame,
                                     (void **)dst,
                                     src, size, 0, 0);

    if (ret.code != RC_OK)
        return res;
    
    res = ret.consumed;
 
    //asn_fprint(stdout,&asn_DEF_MessageFrame,&dst);

    //parse_decoded_j2735(*dst);

    return res;
}
 
int parse_decoded_j2735(MessageFrame_t *msg)
{ 
    switch(msg->messageId){
        case DSRC_ID_BSM:
            printf(">> Parse J2735 : BSM\n");
            break;
        case DSRC_ID_PVD:
            printf(">> Parse J2735 : PVD\n");
            break;
        case DSRC_ID_SPAT:
            printf(">> Parse J2735 : SPAT\n"); 
            break;  
        case DSRC_ID_MAP:
            printf(">> Parse J2735 : MAP\n");
            break;
    }
    return 0;
}
 

int parse_map(MapData_t *map){

    for (int i = 0; i < map->intersections->list.count; i++)
    {  
         struct IntersectionGeometry *ptr= map->intersections->list.array[i]; 
        // MISSION : MAP ???????????? ????????? IntersectionGeometry??? Intersection ID ??????
        //           Intersection ??? Ref Position??? ???????????? LaneSet??? Node ?????? ?????? ??? ??????
        //           Node??? ????????? ????????? Line ??? ID??? SignalGroupID??? ?????? 
    }

    return 0;
}

int parse_spat(SPAT_t *spat){

    for (int i = 0; i < spat->intersections.list.count; i++)
    {
        struct IntersectionState *ptr = spat->intersections.list.array[i];

        // MISSION : MAP ???????????? ????????? Intersection ID ??????
        //           Intersection ??? Ref Position??? ???????????? Offset Node ?????? ??????
        //           Node??? ????????? ????????? Line ??? ID??? SignalGroupID??? ??????


    }

    return 0;
}

int parse_bsm(BasicSafetyMessage_t *bsm){
 
    // MISSION : BSM ??? temporary ID ??????
    //           ????????? ??????(??????,??????,??????)??? ?????? ??????, ?????? ??????
    printf("[BSM]\n");

    //printf("%d\n", bsm->coreData.id.size);

    //printf("????????? ????????? ID: 0x%02X%02X%02X%02X\n", bsm->coreData.id.buf[0], bsm->coreData.id.buf[1], bsm->coreData.id.buf[2], bsm->coreData.id.buf[3]);


    printf("??? BSM ???????????? 1??? ???????????? ??? : %ld\n", bsm->coreData.msgCnt);
    printf("?????? ?????? UTC ?????? (???) : %ld\n", bsm->coreData.secMark);
    printf("?????? ????????? ?????? (??????) : %ld\n", bsm->coreData.lat);
    printf("?????? ????????? ?????? (??????) : %ld\n", bsm->coreData.Long);
    printf("?????? ????????? ?????? (??????) : %ld\n", bsm->coreData.elev);
    printf("?????? ????????? ?????? ????????? (SemiMajorAxisOrientation) : %ld\n", bsm->coreData.accuracy.orientation);
    printf("?????? ????????? ?????? ????????? (SemiMajorAxisAccuracy) : %ld\n", bsm->coreData.accuracy.semiMajor);
    printf("?????? ????????? ?????? ????????? (SemiMinorAxisAccuracy) : %ld\n", bsm->coreData.accuracy.semiMinor);
    printf("?????? ????????? ????????? ?????? : %ld\n", (long int)bsm->coreData.transmission);
    printf("?????? ????????? ?????? : %ld\n", bsm->coreData.speed);
    printf("?????? ????????? ?????? ?????? : %ld\n", bsm->coreData.heading);
    printf("?????? ????????? ????????? (Steering Wheel Angle) : %ld\n", bsm->coreData.angle);
    printf("?????? ????????? ????????? ?????? (Lateral Axis) : %ld\n", bsm->coreData.accelSet.lat);
    printf("?????? ????????? ????????? ?????? (Longitudinal Axis) : %ld\n", bsm->coreData.accelSet.Long);
    printf("?????? ????????? ????????? ?????? (Vertical Axis) : %ld\n", bsm->coreData.accelSet.vert);
    printf("?????? ????????? ????????? ?????? (Yaw rate) : %ld\n", bsm->coreData.accelSet.yaw);


    printf("?????? ????????? ??????????????? ?????? : ");
    for (int i = 7; i >= 0; --i) { //8?????? ???????????? ?????????
        int result = *(bsm->coreData.brakes.wheelBrakes.buf) >> i & 1;
        printf("%d", result);
    }
    printf("\n");

    printf("?????? ????????? ABS ???????????? ?????? %ld\n", bsm->coreData.brakes.abs);
    printf("?????? ????????? ?????? ???????????? ?????? %ld\n", bsm->coreData.brakes.auxBrakes);
    printf("?????? ????????? ???????????? Boost ?????? ?????? %ld\n", bsm->coreData.brakes.brakeBoost);
    printf("?????? ????????? SCS ?????? %ld\n", bsm->coreData.brakes.scs);
    printf("?????? ????????? TCS ?????? %ld\n", bsm->coreData.brakes.traction);
    printf("????????? ?????? %ld\n", bsm->coreData.size.length);
    printf("????????? ?????? %ld\n", bsm->coreData.size.width);

    return 0;
}