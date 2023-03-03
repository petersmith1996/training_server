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
        // MISSION : MAP 메시지에 포함된 IntersectionGeometry별 Intersection ID 추출
        //           Intersection 내 Ref Position을 기준으로 LaneSet의 Node 좌표 계산 및 출력
        //           Node로 연결된 차선의 Line 별 ID와 SignalGroupID를 출력 
    }

    return 0;
}

int parse_spat(SPAT_t *spat){

    for (int i = 0; i < spat->intersections.list.count; i++)
    {
        struct IntersectionState *ptr = spat->intersections.list.array[i];

        // MISSION : MAP 메시지에 포함된 Intersection ID 추출
        //           Intersection 내 Ref Position을 기준으로 Offset Node 좌표 추출
        //           Node로 연결된 차선의 Line 별 ID와 SignalGroupID를 출력


    }

    return 0;
}

int parse_bsm(BasicSafetyMessage_t *bsm){
 
    // MISSION : BSM 내 temporary ID 추출
    //           차량의 위치(위도,경도,고도)와 주행 방향, 속도 출력
    printf("[BSM]\n");

    //printf("%d\n", bsm->coreData.id.size);

    //printf("할당된 대학별 ID: 0x%02X%02X%02X%02X\n", bsm->coreData.id.buf[0], bsm->coreData.id.buf[1], bsm->coreData.id.buf[2], bsm->coreData.id.buf[3]);


    printf("매 BSM 전송마다 1씩 증가하는 값 : %ld\n", bsm->coreData.msgCnt);
    printf("전송 시점 UTC 시간 (초) : %ld\n", bsm->coreData.secMark);
    printf("현재 차량의 위치 (위도) : %ld\n", bsm->coreData.lat);
    printf("현재 차량의 위치 (경도) : %ld\n", bsm->coreData.Long);
    printf("현재 차량의 위치 (고도) : %ld\n", bsm->coreData.elev);
    printf("현재 차량의 위치 정확도 (SemiMajorAxisOrientation) : %ld\n", bsm->coreData.accuracy.orientation);
    printf("현재 차량의 위치 정확도 (SemiMajorAxisAccuracy) : %ld\n", bsm->coreData.accuracy.semiMajor);
    printf("현재 차량의 위치 정확도 (SemiMinorAxisAccuracy) : %ld\n", bsm->coreData.accuracy.semiMinor);
    printf("현재 차량의 변속기 상태 : %ld\n", (long int)bsm->coreData.transmission);
    printf("현재 차량의 속도 : %ld\n", bsm->coreData.speed);
    printf("현재 차량의 진행 방향 : %ld\n", bsm->coreData.heading);
    printf("현재 차량의 조향각 (Steering Wheel Angle) : %ld\n", bsm->coreData.angle);
    printf("현재 차량의 가속도 정보 (Lateral Axis) : %ld\n", bsm->coreData.accelSet.lat);
    printf("현재 차량의 가속도 정보 (Longitudinal Axis) : %ld\n", bsm->coreData.accelSet.Long);
    printf("현재 차량의 가속도 정보 (Vertical Axis) : %ld\n", bsm->coreData.accelSet.vert);
    printf("현재 차량의 가속도 정보 (Yaw rate) : %ld\n", bsm->coreData.accelSet.yaw);


    printf("현재 차량의 휠브레이크 상태 : ");
    for (int i = 7; i >= 0; --i) { //8자리 숫자까지 나타냄
        int result = *(bsm->coreData.brakes.wheelBrakes.buf) >> i & 1;
        printf("%d", result);
    }
    printf("\n");

    printf("현재 차량의 ABS 브레이크 상태 %ld\n", bsm->coreData.brakes.abs);
    printf("현재 차량의 주차 브레이크 상태 %ld\n", bsm->coreData.brakes.auxBrakes);
    printf("현재 차량의 브레이크 Boost 활성 상태 %ld\n", bsm->coreData.brakes.brakeBoost);
    printf("현재 차량의 SCS 상태 %ld\n", bsm->coreData.brakes.scs);
    printf("현재 차량의 TCS 상태 %ld\n", bsm->coreData.brakes.traction);
    printf("차량의 길이 %ld\n", bsm->coreData.size.length);
    printf("차량의 너비 %ld\n", bsm->coreData.size.width);

    return 0;
}