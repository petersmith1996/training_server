#ifndef TR_UTCTIME_H
#define TR_UTCTIME_H

namespace training{
    #pragma pack(1)
    struct St_UTCTime{
        uint16_t year;
        uint8_t month;
        uint8_t day;
        uint8_t hour;
        uint8_t min;
        uint16_t msec;
    };
    #pragma pack()
}

#endif