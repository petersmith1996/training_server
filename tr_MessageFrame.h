#include "tr_J2735.h"
#include "header.h"
#include "utcTime.h"
#include "const.h"
#include <iostream>
#include <sys/time.h>
#include "sample/j2735.h"

#ifndef TR_MESSAGEFRAME_H
#define TR_MESSAGEFRAME_H

using namespace std;
//using namespace training;

namespace training{

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//////              Payload
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

    #pragma pack(1)
    struct St_Position{
        int32_t lat;
        int32_t lon;
        int32_t elev;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_ACK{
        unsigned char Code;
        uint16_t ServiceFlag;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_SERVER_TX_J2735_DATA{
        St_UTCTime UTCTime;
        St_Position Position;
        unsigned char Tx_Result;
        uint PSID;
        unsigned char Channel;
        uint8_t timeslot;
        unsigned char Tx_Power;
        unsigned char Tx_Rate;
        unsigned char priority;
        unsigned char dot2;
        uint16_t MessageID;
        uint16_t EncodedMessageLength;
        uint8_t* EncodedMessage;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_SIMULATOR_TX_J2735_DATA_WITHOUT_MSG{
        St_UTCTime UTCTime;
        uint16_t MessageID;
        uint16_t EncodedMessageLength;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_SIMULATOR_TX_J2735_DATA{
        St_UTCTime UTCTime;
        uint16_t MessageID;
        uint16_t EncodedMessageLength;
        uint8_t* EncodedMessage;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_JSON{
        St_UTCTime UTCTime;
        uint16_t MessageID;
        uint16_t JsonMessageLength;
        uint8_t* JsonMessage;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_Payload_SIGN{
        uint8_t FullDeviceID[6];
        uint16_t KeyCodeLength;
        uint8_t KeyCode[4];
    };
    #pragma pack()

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//////              MessageFrame
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

    #pragma pack(1)
    struct St_SERVER_TX_J2735_DATA{
        St_Header header;
        St_Payload_SERVER_TX_J2735_DATA payload;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_SIMULATOR_TX_J2735_DATA{
        St_Header header;
        St_Payload_SIMULATOR_TX_J2735_DATA payload;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_SERVER_OR_CLIENT_JSON_DATA{
        St_Header header;
        St_Payload_JSON payload;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_SERVER_OR_CLIENT_SIGN{
        St_Header header;
        St_Payload_SIGN payload;
    };
    #pragma pack()

    #pragma pack(1)
    struct St_SERVER_OR_SIMULATOR_SIGN_ACK{
        St_Header header;
        St_Payload_ACK payload;
    };
    #pragma pack()

}

#endif //TR_MESSAGEFRAME_H