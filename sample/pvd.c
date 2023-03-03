/*
 * UPER Based client application sample code
 *
 * Copyright (c) 2022, CEST
 *
 */

#include "j2735.h"

int fill_j2735_pvd(MessageFrame_t *dst)
{
    //ASN_STRUCT_RESET(asn_DEF_MessageFrame, dst);

    dst->messageId = 26; // J2735 표준문서 PDF 파일 참조 DE_DSRC_MessageID,  probeVehicleData DSRCmsgID ::= 26 -- PVD 
    dst->value.present = MessageFrame__value_PR_ProbeVehicleData; // MessageFrame::value choice (asn1c)

    ProbeVehicleData_t *ptrPvd = &dst->value.choice.ProbeVehicleData;

    ptrPvd->timeStamp = NULL; // OPTIONAL, not to use
    ptrPvd->segNum = NULL;    // OPTIONAL, not to use
    ptrPvd->regional = NULL;  // OPTIONAL, not to use

    ptrPvd->probeID = (VehicleIdent*)malloc(sizeof(struct VehicleIdent));
    ptrPvd->probeID->name = NULL;         // OPTIONAL, not to use
    ptrPvd->probeID->ownerCode = NULL;    // OPTIONAL, not to use
    ptrPvd->probeID->vehicleClass = NULL; // OPTIONAL, not to use
    ptrPvd->probeID->vin = NULL;          // OPTIONAL, not to use
    ptrPvd->probeID->vehicleType = NULL;  // OPTIONAL, not to use
    ptrPvd->probeID->id = (VehicleID*)malloc(sizeof (struct VehicleID));
    ptrPvd->probeID->id->present = VehicleID_PR_entityID;   
    ptrPvd->probeID->id->choice.entityID.buf = (unsigned char *)malloc(4);
    ptrPvd->probeID->id->choice.entityID.size = 4; 
    ptrPvd->probeID->id->choice.entityID.buf[0] = 0x01;      // (INPUT) <---- 할당된 대학별 ID 입력
    ptrPvd->probeID->id->choice.entityID.buf[1] = 0x01;      // (INPUT) <---- 할당된 대학별 ID 입력
    ptrPvd->probeID->id->choice.entityID.buf[2] = 0x01;      // (INPUT) <---- 할당된 대학별 ID 입력
    ptrPvd->probeID->id->choice.entityID.buf[3] = 0x01;      // (INPUT) <---- 할당된 대학별 ID 입력
  
    //StartVector : PVD를 전송할 시점을 기준의 시간과 차량의 위치, 이동상태 값을 반영  
    ptrPvd->startVector.utcTime = (DDateTime*)malloc(sizeof(struct DDateTime));  
    ptrPvd->startVector.utcTime->year = (DYear_t*)malloc(sizeof(DYear_t));
    ptrPvd->startVector.utcTime->month = (DMonth_t*)malloc(sizeof(DMonth_t)); 
    ptrPvd->startVector.utcTime->day = (DDay_t*)malloc(sizeof(DDay_t)); 
    ptrPvd->startVector.utcTime->hour = (DHour_t*)malloc(sizeof(DHour_t)); 
    ptrPvd->startVector.utcTime->minute = (DMinute_t*)malloc(sizeof(DMinute_t)); 
    ptrPvd->startVector.utcTime->second = (DSecond_t*)malloc(sizeof(DSecond_t)); 
    ptrPvd->startVector.utcTime->offset = NULL; // OPTIONAL, not to use

    *ptrPvd->startVector.utcTime->year = 2022; // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrPvd->startVector.utcTime->month = 1;   // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrPvd->startVector.utcTime->day = 1;     // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrPvd->startVector.utcTime->hour = 0;    // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrPvd->startVector.utcTime->minute = 0;  // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrPvd->startVector.utcTime->second = 0;  // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)

    ptrPvd->startVector.elevation = (DSRC_Elevation_t*)malloc(sizeof(DSRC_Elevation_t));
    ptrPvd->startVector.heading = (Heading_t*)malloc(sizeof(Heading_t));
    ptrPvd->startVector.speed = (TransmissionAndSpeed*)malloc(sizeof(struct TransmissionAndSpeed));
    ptrPvd->startVector.posAccuracy = NULL;     // OPTIONAL, not to use
    ptrPvd->startVector.posConfidence = NULL;   // OPTIONAL, not to use
    ptrPvd->startVector.timeConfidence = NULL;  // OPTIONAL, not to use
    ptrPvd->startVector.speedConfidence = NULL; // OPTIONAL, not to use

    ptrPvd->startVector.Long = 0;                // (INPUT) <--------------- 현재 차량의 위치 (위도) (Longitude, DD 좌표계)
    ptrPvd->startVector.lat = 0;                 // (INPUT) <--------------- 현재 차량의 위치 (경도) (Latitude,  DD 좌표계)
    *ptrPvd->startVector.elevation = 0;          // (INPUT) <--------------- 현재 차량의 위치 (고도) (Elevation)   
    *ptrPvd->startVector.heading = 0;            // (INPUT) <--------------- 현재 차량의 주행 방향 (북쪽 0도)           
    ptrPvd->startVector.speed->speed = 0;        // (INPUT) <--------------- 현재 차량의 속도        
    ptrPvd->startVector.speed->transmisson = 0;  // (INPUT) <--------------- 현재 차량의 변속기 상태          
 
    ptrPvd->vehicleType.hpmsType = (VehicleType_t*)malloc(sizeof(VehicleType_t));
    ptrPvd->vehicleType.keyType = NULL;       // OPTIONAL, not to use
    ptrPvd->vehicleType.fuelType = NULL;      // OPTIONAL, not to use
    ptrPvd->vehicleType.iso3883 = NULL;       // OPTIONAL, not to use
    ptrPvd->vehicleType.regional = NULL;      // OPTIONAL, not to use
    ptrPvd->vehicleType.responderType = NULL; // OPTIONAL, not to use
    ptrPvd->vehicleType.responseEquip = NULL; // OPTIONAL, not to use
    ptrPvd->vehicleType.role = NULL;          // OPTIONAL, not to use
    ptrPvd->vehicleType.vehicleType = NULL;   // OPTIONAL, not to use
    *ptrPvd->vehicleType.hpmsType = VehicleType_car; 
 
    // PVD 전송 직전에 전송한 PVD startVector 시간, 위치, 이동상태를 입력 
    ptrPvd->snapshots.list.count = 1; 
    ptrPvd->snapshots.list.array = (Snapshot**)malloc(sizeof(struct Snapshot *));
    ptrPvd->snapshots.list.array[0] = (Snapshot*)malloc(sizeof(struct Snapshot));
    struct Snapshot *ptrSnapshot = ptrPvd->snapshots.list.array[0]; 

    ptrSnapshot->thePosition.utcTime = (DDateTime*)malloc(sizeof(struct DDateTime));
    ptrSnapshot->thePosition.utcTime->year = (DYear_t*)malloc(sizeof(DYear_t));
    ptrSnapshot->thePosition.utcTime->month = (DMonth_t*)malloc(sizeof(DMonth_t));
    ptrSnapshot->thePosition.utcTime->day = (DDay_t*)malloc(sizeof(DDay_t));
    ptrSnapshot->thePosition.utcTime->hour = (DHour_t*)malloc(sizeof(DHour_t));
    ptrSnapshot->thePosition.utcTime->minute = (DMinute_t*)malloc(sizeof(DMinute_t));
    ptrSnapshot->thePosition.utcTime->second = (DSecond_t*)malloc(sizeof(DSecond_t));
    ptrSnapshot->thePosition.utcTime->offset = NULL; // OPTIONAL, not to use

    ptrSnapshot->thePosition.elevation = (DSRC_Elevation_t*)malloc(sizeof(DSRC_Elevation_t));
    ptrSnapshot->thePosition.speed = (TransmissionAndSpeed*)malloc(sizeof(struct TransmissionAndSpeed));
    ptrSnapshot->thePosition.heading = (Heading_t*)malloc(sizeof(Heading_t));
    ptrSnapshot->thePosition.posAccuracy = NULL;     // OPTIONAL, not to use
    ptrSnapshot->thePosition.posConfidence = NULL;   // OPTIONAL, not to use
    ptrSnapshot->thePosition.timeConfidence = NULL;  // OPTIONAL, not to use
    ptrSnapshot->thePosition.speedConfidence = NULL; // OPTIONAL, not to use

    *ptrSnapshot->thePosition.utcTime->year = 2022;       // (INPUT) <--------------- 현재 UTC 시간 입력 (년도)
    *ptrSnapshot->thePosition.utcTime->month = 1;         // (INPUT) <--------------- 현재 UTC 시간 입력 (월)
    *ptrSnapshot->thePosition.utcTime->day = 1;           // (INPUT) <--------------- 현재 UTC 시간 입력 (일)
    *ptrSnapshot->thePosition.utcTime->hour = 0;          // (INPUT) <--------------- 현재 UTC 시간 입력 (시)
    *ptrSnapshot->thePosition.utcTime->minute = 0;        // (INPUT) <--------------- 현재 UTC 시간 입력 (분)
    *ptrSnapshot->thePosition.utcTime->second = 0;        // (INPUT) <--------------- 현재 UTC 시간 입력 (초)
    
    ptrSnapshot->thePosition.lat = 0;                // (INPUT) <--------------- 현재 차량의 위치 (위도) (Longitude, DD 좌표계)
    ptrSnapshot->thePosition.Long = 0;               // (INPUT) <--------------- 현재 차량의 위치 (경도) (Latitude,  DD 좌표계) 
    *ptrSnapshot->thePosition.elevation = 0;         // (INPUT) <--------------- 현재 차량의 위치 (고도) (Elevation)   
    *ptrSnapshot->thePosition.heading = 0;           // (INPUT) <--------------- 현재 차량의 주행 방향 (북쪽 0도)               
    ptrSnapshot->thePosition.speed->speed = 0;       // (INPUT) <-------------- -현재 차량의 속도                  
    ptrSnapshot->thePosition.speed->transmisson = 0; // (INPUT) <--------------- 현재 차량의 변속기 상태          
  
    return 0;
}