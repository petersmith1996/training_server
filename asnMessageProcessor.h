//#include "tr_J2735.h"
#include "header.h"
#include "utcTime.h"
#include "const.h"
#include <iostream>
#include <sys/time.h>
#include "sample/j2735.h"
#include <json-c/json.h>
#include "messageProcessor.h"

class asnMessageProcessor{
public:

    static void JsonCvt_OCTET_STRING(OCTET_STRING_t* src, json_object** Job){
        uint8_t* tmp = (uint8_t*)malloc(src->size);
        for(int i = 0; i<src->size; i++){
            sprintf((char*)&tmp[i], "%c", src->buf[i]);
        }
        //memcpy(tmp, src->buf, src->size);
        *Job = json_object_new_string((char*)tmp);
        free(tmp);
    }

    static void JsonCvt_IA5String(IA5String_t* src, json_object** Job){
        JsonCvt_OCTET_STRING(src, Job);
    }

    static void JsonCvt_SemiMajorAxisAccuracy(SemiMajorAxisAccuracy_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_SemiMinorAxisAccuracy(SemiMinorAxisAccuracy_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }


    static void JsonCvt_SemiMajorAxisOrientation(SemiMajorAxisOrientation_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_PositionalAccuracy(PositionalAccuracy* src, json_object** Job){
        json_object* semiMajor = json_object_new_object();
        JsonCvt_SemiMajorAxisAccuracy(src->semiMajor, &semiMajor);
        json_object_object_add(*Job, "semiMajor", semiMajor);

        json_object* semiMinor = json_object_new_object();
        JsonCvt_SemiMinorAxisAccuracy(src->semiMinor, &semiMinor);
        json_object_object_add(*Job, "semiMinor", semiMinor);

        json_object* orientation = json_object_new_object();
        JsonCvt_SemiMajorAxisOrientation(src->orientation, &orientation);
        json_object_object_add(*Job, "orientation", orientation);
    }

    static void JsonCvt_DYear(DYear_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DMonth(DMonth_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DDay(DDay_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DHour(DHour_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DMinute(DMinute_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DSecond(DSecond_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_DOffset(DOffset_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }


    static void JsonCvt_DDateTime(DDateTime* src, json_object* Job){

        if(src->year != NULL){
            json_object* year = json_object_new_object();
            JsonCvt_DYear(*src->year, &year);
            json_object_object_add(Job, "year", year);
        }
        if(src->month != NULL){
            json_object* month = json_object_new_object();
            JsonCvt_DMonth(*src->month, &month);
            json_object_object_add(Job, "month", month);
        }
        if(src->day != NULL){
            json_object* day = json_object_new_object();
            JsonCvt_DDay(*src->day, &day);
            json_object_object_add(Job, "day", day);
        }
        if(src->hour != NULL){
            json_object* hour = json_object_new_object();
            JsonCvt_DHour(*src->hour, &hour);
            json_object_object_add(Job, "hour", hour);
        }
        if(src->minute != NULL){
            json_object* minute = json_object_new_object();
            JsonCvt_DMinute(*src->minute, &minute);
            json_object_object_add(Job, "minute", minute);
        }
        if(src->second != NULL){
            json_object* second = json_object_new_object();
            JsonCvt_DSecond(*src->second, &second);
            json_object_object_add(Job, "second", second);
        }
        if(src->offset != NULL){
            json_object* offset = json_object_new_object();
            JsonCvt_DOffset(*src->offset, &offset);
            json_object_object_add(Job, "offset", offset);
        }
    }

    static void JsonCvt_MsgCount(Longitude_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }
    static void JsonCvt_TemporaryID(TemporaryID_t src, json_object** Job){
        char id_buf[9];
        sprintf(id_buf, "%02X%02X%02X%02X", src.buf[0], src.buf[1], src.buf[2], src.buf[3]);
        *Job = json_object_new_string((const char*)id_buf);
    }


    static void JsonCvt_Longitude(Longitude_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_Latitude(Latitude_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_Elevation(DSRC_Elevation_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_Heading(Heading_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_CoarseHeading(Heading_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_Speed(Speed_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_SteeringWheelAngle(SteeringWheelAngle_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_VerticalAcceleration(VerticalAcceleration_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_YawRate(YawRate_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_AccelerationSet4Way(AccelerationSet4Way_t src, json_object** Job){
        json_object* lat = json_object_new_object();
        JsonCvt_Latitude(src.lat, &lat);
        json_object_object_add(*Job, "lat", (lat));

        json_object* Long = json_object_new_object();
        JsonCvt_Longitude(src.Long, &Long);
        json_object_object_add(*Job, "long", (Long));

        json_object* vert = json_object_new_object();
        JsonCvt_VerticalAcceleration(src.vert, &vert);
        json_object_object_add(*Job, "vert", (vert));

        json_object* yaw = json_object_new_object();
        JsonCvt_YawRate(src.yaw, &yaw);
        json_object_object_add(*Job, "yaw", (yaw));
    }

    static void JsonCvt_BrakeSystemStatus(BrakeSystemStatus_t src, json_object** Job){
        json_object_object_add(*Job, "abs", json_object_new_string(asn_SPC_AntiLockBrakeStatus_specs_1.value2enum[src.abs].enum_name));
        json_object_object_add(*Job, "auxBrakes", json_object_new_string(asn_SPC_AuxiliaryBrakeStatus_specs_1.value2enum[src.auxBrakes].enum_name));
        json_object_object_add(*Job, "brakeBoost", json_object_new_string(asn_SPC_BrakeBoostApplied_specs_1.value2enum[src.brakeBoost].enum_name));
        json_object_object_add(*Job, "scs", json_object_new_string(asn_SPC_StabilityControlStatus_specs_1.value2enum[src.scs].enum_name));
        json_object_object_add(*Job, "traction", json_object_new_string(asn_SPC_TractionControlStatus_specs_1.value2enum[src.traction].enum_name));
        char wheelBrakes[3];
        sprintf(wheelBrakes, "%02X", src.wheelBrakes.buf[0]);
        json_object_object_add(*Job, "wheelBrakes", json_object_new_string(wheelBrakes));
    }

    static void JsonCvt_VehicleWidth(VehicleWidth_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_VehicleLength(VehicleLength_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_VehicleSize(VehicleSize_t src, json_object** Job){

        json_object* width = json_object_new_object();
        JsonCvt_VehicleWidth(src.width, &width);
        json_object_object_add(*Job, "width", (width));

        json_object* length = json_object_new_object();
        JsonCvt_VehicleLength(src.length, &length);
        json_object_object_add(*Job, "length", (length));
    }

    static void JsonCvt_BSMcoreData(BSMcoreData_t src, json_object** Job){

        json_object* msgCnt = json_object_new_object();
        JsonCvt_MsgCount(src.msgCnt, &msgCnt);
        json_object_object_add(*Job, "msgCnt", msgCnt);

        json_object* id = json_object_new_object();
        JsonCvt_TemporaryID(src.id, &id);
        json_object_object_add(*Job, "id", id);

        json_object* secMark = json_object_new_object();
        JsonCvt_DSecond(src.secMark, &secMark);
        json_object_object_add(*Job, "secMark", secMark);

        json_object* lat = json_object_new_object();
        JsonCvt_Latitude(src.lat, &lat);
        json_object_object_add(*Job, "lat", lat);

        json_object* Long = json_object_new_object();
        JsonCvt_Longitude(src.Long, &Long);
        json_object_object_add(*Job, "long", Long);

        json_object* elev = json_object_new_object();
        JsonCvt_Elevation(src.elev, &elev);
        json_object_object_add(*Job, "elev", elev);

        json_object* accuracy = json_object_new_object();
        JsonCvt_PositionalAccuracy(&src.accuracy, &accuracy);
        json_object_object_add(*Job, "accuracy", accuracy);

        json_object* transmission;
        JsonCvt_TransmissionState(src.transmission, &transmission);
        json_object_object_add(*Job, "transmission", transmission);

        json_object* speed = json_object_new_object();
        JsonCvt_Speed(src.speed, &speed);
        json_object_object_add(*Job, "speed", speed);

        json_object* heading = json_object_new_object();
        JsonCvt_Heading(src.heading, &heading);
        json_object_object_add(*Job, "heading", heading);

        json_object* angle = json_object_new_object();
        JsonCvt_SteeringWheelAngle(src.angle, &angle);
        json_object_object_add(*Job, "angle", angle);

        json_object* accelSet = json_object_new_object();
        JsonCvt_AccelerationSet4Way(src.accelSet, &accelSet);
        json_object_object_add(*Job, "accelSet", accelSet);

        json_object* brakes = json_object_new_object();
        JsonCvt_BrakeSystemStatus(src.brakes, &brakes);
        json_object_object_add(*Job, "brakes", brakes);

        json_object* size = json_object_new_object();
        JsonCvt_VehicleSize(src.size, &size);
        json_object_object_add(*Job, "size", size);
    }

    static void JsonCvt_TransmissionState(TransmissionState_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_TransmissionState_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_Velocity(Velocity_t src, json_object** Job){
        *Job = json_object_new_int(src);

    }

    static void JsonCvt_TransmissionAndSpeed(TransmissionAndSpeed_t* src, json_object** Job){
        json_object* speed = json_object_new_object();
        json_object* transmisson = json_object_new_object();
        JsonCvt_TransmissionState(src->transmisson, &transmisson);
        JsonCvt_Velocity(src->speed, &speed);
        json_object_object_add(*Job, "transmission", transmisson);
        json_object_object_add(*Job, "speed", speed);
    }

    static void JsonCvt_FullPositionVector(FullPositionVector_t* src, json_object** Job){
        if(src->utcTime != NULL){
            json_object* utcTime = json_object_new_object();
            JsonCvt_DDateTime(src->utcTime, utcTime);
            json_object_object_add(*Job, "utcTime", utcTime);
        }

        json_object* Long = json_object_new_object();
        JsonCvt_Longitude(src->Long, &Long);
        json_object_object_add(*Job, "long", Long);

        json_object* lat = json_object_new_object();
        JsonCvt_Latitude(src->lat, &lat);
        json_object_object_add(*Job, "lat", lat);

        if(src->elevation != NULL){
            json_object* elevation = json_object_new_object();
            JsonCvt_Elevation(*src->elevation, &elevation);
            json_object_object_add(*Job, "elevation", elevation);
        }
        if(src->heading != NULL){
            json_object* heading = json_object_new_object();
            JsonCvt_Heading(*src->heading, &heading);
            json_object_object_add(*Job, "heading", heading);
        }
        if(src->speed != NULL){
            json_object* speed = json_object_new_object();
            JsonCvt_TransmissionAndSpeed(src->speed, &speed);
            json_object_object_add(*Job, "speed", speed);
        }
        if(src->posAccuracy != NULL){
            json_object* posAccuracy = json_object_new_object();
            JsonCvt_PositionalAccuracy(src->posAccuracy, &posAccuracy);
            json_object_object_add(*Job, "posAccuracy", posAccuracy);
        }
        if(src->timeConfidence != NULL){
            json_object* timeConfidence = json_object_new_object();
            json_object_object_add(*Job, "timeConfidence", timeConfidence);
        }
        if(src->posConfidence != NULL){
            json_object* posConfidence = json_object_new_object();
            json_object_object_add(*Job, "posConfidence", posConfidence);
        }
        if(src->speedConfidence != NULL){
            json_object* speedConfidence = json_object_new_object();
            json_object_object_add(*Job, "speedConfidence", speedConfidence);
        }
    }

    static void JsonCvt_OffsetLL_B18(OffsetLL_B18_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_VertOffset_B12(VertOffset_B12_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_TimeOffset(TimeOffset_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_PathHistoryPoint(PathHistoryPoint_t* src, json_object** Job){
        json_object* elevationOffset = json_object_new_object();
        JsonCvt_VertOffset_B12(src->elevationOffset, &elevationOffset);
        json_object_object_add(*Job, "elevationOffset", elevationOffset);

        json_object* latOffset = json_object_new_object();
        JsonCvt_OffsetLL_B18(src->latOffset, &latOffset);
        json_object_object_add(*Job, "latOffset", latOffset);

        json_object* lonOffset = json_object_new_object();
        JsonCvt_OffsetLL_B18(src->lonOffset, &lonOffset);
        json_object_object_add(*Job, "lonOffset", lonOffset);

        json_object* timeOffset = json_object_new_object();
        JsonCvt_TimeOffset(src->timeOffset, &timeOffset);
        json_object_object_add(*Job, "timeOffset", timeOffset);

        if (src->speed != NULL){
            json_object* speed = json_object_new_object();
            JsonCvt_Speed(*src->speed, &speed);
            json_object_object_add(*Job, "speed", speed);
        }
        if (src->posAccuracy != NULL){
            json_object* posAccuracy = json_object_new_object();
            JsonCvt_PositionalAccuracy(src->posAccuracy, &posAccuracy);
            json_object_object_add(*Job, "posAccuracy", posAccuracy);
        }
        if (src->heading != NULL){
            json_object* heading = json_object_new_object();
            JsonCvt_CoarseHeading(*src->heading, &heading);
            json_object_object_add(*Job, "heading", heading);
        }                            
    }

    static void JsonCvt_PathHistoryPointList(PathHistoryPointList_t* src, json_object** Job){
        int len = src->list.count;
        for(int i = 0; i<len; i++){
            json_object* crumbData_element = json_object_new_object();
            JsonCvt_PathHistoryPoint(src->list.array[i], &crumbData_element);
            json_object_array_add(*Job, crumbData_element);
        }
    }

    static void JsonCvt_GNSSstatus(GNSSstatus_t src, json_object** Job){
        char tmp[3];
        sprintf(tmp, "%02X", src.buf[0]);
        *Job = json_object_new_string(tmp);
    }

    static void JsonCvt_PathHistory(PathHistory_t* src, json_object** Job){

        if(src->initialPosition != NULL){
            json_object* initialPosition = json_object_new_object();
            JsonCvt_FullPositionVector(src->initialPosition, &initialPosition);
            json_object_object_add(*Job, "initialPosition", initialPosition);
        }
        if(src->currGNSSstatus != NULL){
            json_object* currGNSSstatus = json_object_new_object();
            JsonCvt_GNSSstatus(*src->currGNSSstatus, &currGNSSstatus);
            json_object_object_add(*Job, "currGNSSstatus", currGNSSstatus);
        }

        json_object* crumbData = json_object_new_array();
        JsonCvt_PathHistoryPointList(&src->crumbData, &crumbData);
        json_object_object_add(*Job, "crumbData", crumbData);
    }

    static void JsonCvt_VehicleEventFlags(VehicleEventFlags_t src, json_object** Job){
        char tmp[5];
        sprintf(tmp, "%02X%02X", src.buf[0], src.buf[1]);
        *Job = json_object_new_string(tmp);
    }
    
    static void JsonCvt_RadiusOfCurvature(RadiusOfCurvature_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }
    
    static void JsonCvt_Confidence(Confidence_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_PathPrediction(PathPrediction_t* src, json_object** Job){
        json_object* radiusOfCurve = json_object_new_object();
        JsonCvt_RadiusOfCurvature(src->radiusOfCurve, &radiusOfCurve);
        json_object_object_add(*Job, "radiusOfCurve", radiusOfCurve);
                     
        json_object* confidence = json_object_new_object();
        JsonCvt_Confidence(src->confidence, &confidence);
        json_object_object_add(*Job, "confidence", confidence);
    }
    
    static void JsonCvt_ExteriorLights(ExteriorLights_t* src, json_object** Job){
        char tmp[5];
        sprintf(tmp, "%02X%02X", src->buf[0], src->buf[1]);
        *Job = json_object_new_string(tmp);
    }
    
    static void JsonCvt_SSPindex(SSPindex_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_SirenInUse(SirenInUse_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_SirenInUse_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_LightbarInUse(LightbarInUse_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_LightbarInUse_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_MultiVehicleResponse(MultiVehicleResponse_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_MultiVehicleResponse_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_PrivilegedEventFlags(PrivilegedEventFlags_t src, json_object** Job){
        char tmp[33];
        for(int i = 0; i>16; i++){
            sprintf(&tmp[2*i], "%02X", src.buf[i]);
        }
        //sprintf(tmp, "%02X%02X", src->buf[0], src->buf[1]);
        *Job = json_object_new_string(tmp);
    }

    static void JsonCvt_PrivilegedEvents(PrivilegedEvents* src, json_object** Job){
        json_object* sspRights = json_object_new_object();
        JsonCvt_SSPindex(src->sspRights, &sspRights);
        json_object_object_add(*Job, "sspRights", sspRights);

        json_object* event = json_object_new_object();
        JsonCvt_PrivilegedEventFlags(src->event, &event);
        json_object_object_add(*Job, "event", event);
    }

    static void JsonCvt_ResponseType(ResponseType_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_ResponseType_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_ITIScodes(ITIScodes_t src, json_object** Job){
        *Job = json_object_new_int(src);
    }

    static void JsonCvt_Priority(Priority_t* src, json_object** Job){
        char* tmp = (char*)malloc(src->size);
        memcpy(tmp, src->buf, src->size);
        *Job = json_object_new_string(tmp);
        free(tmp);
    }

    static void JsonCvt_HeadingSlice(HeadingSlice_t* src, json_object** Job){
        char tmp[33];
        for(int i = 0; i<16; i++){
            sprintf(&tmp[2*i], "%02X", src->buf[i]);
        }
        //sprintf(tmp, "%02X%02X", src->buf[0], src->buf[1]);
        *Job = json_object_new_string(tmp);
    }

    static void JsonCvt_Extent(Extent_t src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_Extent_specs_1.value2enum[src].enum_name);
    }

    static void JsonCvt_EventDescription(EventDescription_t* src, json_object** Job){

        json_object* typeEvent = json_object_new_object();
        JsonCvt_ITIScodes(src->typeEvent, &typeEvent);
        json_object_object_add(*Job, "typeEvent", typeEvent);

        if (src->description != NULL){
            json_object* description = json_object_new_array();
            int len = src->description->list.count;
            for(int i = 0; i< len; i++){
                json_object* description_element = json_object_new_object();
                JsonCvt_ITIScodes(*src->description->list.array[i], &description_element);
                json_object_array_add(description, description_element);
            }
            json_object_object_add(*Job, "description", description);
        }

        if (src->priority != NULL){
            json_object* priority = json_object_new_object();
            JsonCvt_Priority(src->priority, &priority);
            json_object_object_add(*Job, "priority", priority);
        }

        if (src->heading != NULL){
            json_object* heading = json_object_new_object();
            JsonCvt_HeadingSlice(src->heading, &heading);
            json_object_object_add(*Job, "heading", heading);

        }

        if (src->extent != NULL){
            json_object* extent = json_object_new_object();
            JsonCvt_Extent(*src->extent, &extent);
            json_object_object_add(*Job, "extent", extent);
        }

        if (src->regional != NULL){
        }
    }

    static void JsonCvt_EmergencyDetails(EmergencyDetails* src, json_object** Job){
        json_object* sspRights = json_object_new_object();
        JsonCvt_SSPindex(src->sspRights, &sspRights);
        json_object_object_add(*Job, "sspRights", sspRights);
        json_object* sirenUse = json_object_new_object();
        JsonCvt_SirenInUse(src->sirenUse, &sspRights);
        json_object_object_add(*Job, "sirenUse", sirenUse);
        json_object* lightsUse = json_object_new_object();
        JsonCvt_LightbarInUse(src->lightsUse, &lightsUse);
        json_object_object_add(*Job, "lightsUse", lightsUse);
        json_object* multi = json_object_new_object();
        JsonCvt_MultiVehicleResponse(src->multi, &multi);
        json_object_object_add(*Job, "multi", multi);
        if (src->events != NULL){
            json_object* events = json_object_new_object();
            JsonCvt_PrivilegedEvents(src->events, &events);
            json_object_object_add(*Job, "events", events);
        }
        if (src->responseType != NULL){
            json_object* responseType = json_object_new_object();
            JsonCvt_ResponseType(*src->responseType, &responseType);
            json_object_object_add(*Job, "responseType", responseType);
        }

    }

    static void JsonCvt_VehicleSafetyExtensions(VehicleSafetyExtensions_t* src, json_object** Job){
        if (src->events != NULL){
            json_object* events = json_object_new_object();
            JsonCvt_VehicleEventFlags(*src->events, &events);
            json_object_object_add(*Job, "events", events);
        }
        if (src->pathHistory != NULL){
            json_object* pathHistory = json_object_new_object();
            JsonCvt_PathHistory(src->pathHistory, &pathHistory);
            json_object_object_add(*Job, "pathHistory", pathHistory);
        }
        if (src->pathPrediction != NULL){
            json_object* pathPrediction = json_object_new_object();
            JsonCvt_PathPrediction(src->pathPrediction, &pathPrediction);
            json_object_object_add(*Job, "pathPrediction", pathPrediction);
        }
        if (src->lights != NULL){
            json_object* lights = json_object_new_object();
            JsonCvt_ExteriorLights(src->lights, &lights);
            json_object_object_add(*Job, "lights", lights);
        }
#ifdef VehicleSafetyExtensions_timestamp
        if (src->partII->list.array[i]->partII_Value.choice.VehicleSafetyExtensions.timestamp != NULL){
        }
#endif

#ifdef VehicleSafetyExtensions_height
        if (src->partII->list.array[i]->partII_Value.choice.VehicleSafetyExtensions.height != NULL){
        }
#endif
    }

    static void JsonCvt_BSMpartIIExtension(BasicSafetyMessage_t* src, json_object** Job){
        int partII_count = src->partII->list.count;
        for( int i = 0; i< partII_count; i++){
            json_object* partII_element = json_object_new_object();

            json_object* partII_element_value = json_object_new_object();
            if (src->partII->list.array[i]->partII_Value.present == BSMpartIIExtension__partII_Value_PR_VehicleSafetyExtensions){
                JsonCvt_VehicleSafetyExtensions(&src->partII->list.array[i]->partII_Value.choice.VehicleSafetyExtensions, &partII_element_value);


            }

            else if (src->partII->list.array[i]->partII_Value.present == BSMpartIIExtension__partII_Value_PR_SpecialVehicleExtensions){
                if (src->partII->list.array[i]->partII_Value.choice.SpecialVehicleExtensions.vehicleAlerts != NULL){
                    json_object* vehicleAlerts = json_object_new_object();
                    JsonCvt_EmergencyDetails(src->partII->list.array[i]->partII_Value.choice.SpecialVehicleExtensions.vehicleAlerts, &vehicleAlerts);
                    json_object_object_add(partII_element_value, "vehicleAlerts", vehicleAlerts);

                }
                if (src->partII->list.array[i]->partII_Value.choice.SpecialVehicleExtensions.description != NULL){
                    json_object* description = json_object_new_object();
                    JsonCvt_EventDescription(src->partII->list.array[i]->partII_Value.choice.SpecialVehicleExtensions.description, &description);
                    json_object_object_add(partII_element_value, "description", description);

                }
                if (src->partII->list.array[i]->partII_Value.choice.SpecialVehicleExtensions.trailers != NULL){
                }

            }

            else if (src->partII->list.array[i]->partII_Value.present == BSMpartIIExtension__partII_Value_PR_SupplementalVehicleExtensions){

            }
            json_object_object_add(partII_element, "partII-value", partII_element_value);
            json_object_array_add(*Job, partII_element);
        }

    }

    static void JsonCvt_BasicSafetyMessage(BasicSafetyMessage_t* src, json_object** Job){

        json_object_object_add(*Job, "messageId", json_object_new_int(MESSAGE_ID_VALUE_BSM));

        json_object* value = json_object_new_object();

        json_object* coreData = json_object_new_object();
        JsonCvt_BSMcoreData(src->coreData, &coreData);
        json_object_object_add(value, "coreData", coreData);
        
        if(src->partII != NULL){
            json_object* partII = json_object_new_array();
            JsonCvt_BSMpartIIExtension(src, &partII);
            json_object_object_add(value, "partII", partII);
        }

        if(src->regional != NULL){
            
        }

        json_object_object_add(*Job, "value", value);
    }

    static void JsonCvt_IntersectionID(IntersectionID_t* src, json_object** Job){
        *Job = json_object_new_int(*src);
    }

    static void JsonCvt_RoadRegulatorID(RoadRegulatorID_t* src, json_object** Job){
        *Job = json_object_new_int(*src);
    }

    static void JsonCvt_IntersectionReferenceID(IntersectionReferenceID_t* src, json_object** Job){
        if(src->region != NULL){
            json_object* region = json_object_new_object();
            JsonCvt_RoadRegulatorID(src->region, &region);
            json_object_object_add(*Job, "region", region);
        }
        json_object* id = json_object_new_object();
        JsonCvt_IntersectionID(&src->id, &id);
        json_object_object_add(*Job, "id", id);
    }

    static void JsonCvt_Position3D(Position3D_t* src, json_object** Job){
        json_object* lat = json_object_new_object();
        JsonCvt_Latitude(src->lat, &lat);
        json_object_object_add(*Job, "lat", lat);

        json_object* Long = json_object_new_object();
        JsonCvt_Longitude(src->Long, &Long);
        json_object_object_add(*Job, "long", Long);

        if(src->elevation != NULL){
            json_object* elevation = json_object_new_object();
            JsonCvt_Elevation(*src->elevation, &elevation);
            json_object_object_add(*Job, "elevation", elevation);
        }
    }

    static void JsonCvt_IntersectionGeometry(IntersectionGeometry_t* src, json_object** Job){
        json_object* id = json_object_new_object();
        JsonCvt_IntersectionReferenceID(&src->id, &id);
        json_object_object_add(*Job, "id", id);

        json_object* refPoint = json_object_new_object();
        JsonCvt_Position3D(&src->refPoint, &refPoint);
        json_object_object_add(*Job, "refPoint", refPoint);

    }

    static void JsonCvt_IntersectionGeometryList(IntersectionGeometryList_t* src, json_object** Job){
        int len = src->list.count;
        for(int i = 0; i<len; i++){
            json_object* intersectionGeometry_element = json_object_new_object();
            JsonCvt_IntersectionGeometry(src->list.array[i], &intersectionGeometry_element);
            json_object_array_add(*Job, intersectionGeometry_element);

            //src->list.array[i]
        }
    }

    static void JsonCvt_MapData(MapData_t* src, json_object** Job){

        json_object_object_add(*Job, "messageId", json_object_new_int(MESSAGE_ID_VALUE_MAP));

        json_object* value = json_object_new_object();

        if (src->intersections != NULL){
            json_object* intersections = json_object_new_array();
            JsonCvt_IntersectionGeometryList(src->intersections, &intersections);
            json_object_object_add(value, "intersections", intersections);

        }
        json_object_object_add(*Job, "value", value);
    }

    static void JsonCvt_DSRC_TimeMark(DSRC_TimeMark_t* src, json_object** Job){
        *Job = json_object_new_int(*src);
    }

    static void JsonCvt_TimeChangeDetails(TimeChangeDetails_t* src, json_object** Job){
        if(src->startTime != NULL){
            json_object* startTime = json_object_new_object();
            JsonCvt_DSRC_TimeMark(src->startTime, &startTime);
            json_object_object_add(*Job, "startTime", startTime);
        }

        json_object* minEndTime = json_object_new_object();
        JsonCvt_DSRC_TimeMark(&src->minEndTime, &minEndTime);
        json_object_object_add(*Job, "minEndTime", minEndTime);

        if(src->maxEndTime != NULL){
            json_object* maxEndTime = json_object_new_object();
            JsonCvt_DSRC_TimeMark(src->maxEndTime, &maxEndTime);
            json_object_object_add(*Job, "maxEndTime", maxEndTime);
        }

        if(src->likelyTime != NULL){
            json_object* likelyTime = json_object_new_object();
            JsonCvt_DSRC_TimeMark(src->likelyTime, &likelyTime);
            json_object_object_add(*Job, "likelyTime", likelyTime);
        }

        if(src->nextTime != NULL){
            json_object* nextTime = json_object_new_object();
            JsonCvt_DSRC_TimeMark(src->nextTime, &nextTime);
            json_object_object_add(*Job, "nextTime", nextTime);
        }
    }

    static void JsonCvt_MovementPhaseState(MovementPhaseState_t* src, json_object** Job){
        *Job = json_object_new_string(asn_SPC_MovementPhaseState_specs_1.value2enum[*src].enum_name);

    }

    static void JsonCvt_MovementEvent(MovementEvent_t* src, json_object** Job){
        json_object* timing = json_object_new_object();
        JsonCvt_TimeChangeDetails(src->timing, &timing);
        json_object_object_add(*Job, "timing", timing);

        json_object* eventState = json_object_new_object();
        JsonCvt_MovementPhaseState(&src->eventState, &eventState);
        json_object_object_add(*Job, "eventState", eventState);

    }

    static void JsonCvt_MovementEventList(MovementEventList_t* src, json_object** Job){
        int len = src->list.count;

        for(int i = 0; i<len; i++){
            json_object* MovementEvent_element = json_object_new_object();
            JsonCvt_MovementEvent(src->list.array[i], &MovementEvent_element);
            json_object_array_add(*Job, MovementEvent_element);

        }
    }

    static void JsonCvt_SignalGroupID(SignalGroupID_t* src, json_object** Job){
        *Job = json_object_new_int(*src);
    }

    static void JsonCvt_DescriptiveName(DescriptiveName_t* src, json_object** Job){
        JsonCvt_IA5String(src, Job);
    }

    static void JsonCvt_MovementState(MovementState_t* src, json_object** Job){
        json_object* signalGroup = json_object_new_array();
        JsonCvt_SignalGroupID(&src->signalGroup, &signalGroup);
        json_object_object_add(*Job, "signalGroup", signalGroup);

        json_object* state_time_speed = json_object_new_array();
        JsonCvt_MovementEventList(&src->state_time_speed, &state_time_speed);
        json_object_object_add(*Job, "state-time-speed", state_time_speed);

        json_object* movementName = json_object_new_object();
        JsonCvt_DescriptiveName(src->movementName, &movementName);
        json_object_object_add(*Job, "movementName", movementName);

    }

    static void JsonCvt_MovementList(MovementList_t* src, json_object** Job){
        int len = src->list.count;

        for(int i = 0; i<len; i++){
            json_object* Movement_element = json_object_new_object();
            JsonCvt_MovementState(src->list.array[i], &Movement_element);
            json_object_array_add(*Job, Movement_element);
        }

    }

    static void JsonCvt_IntersectionState(IntersectionState_t* src, json_object** Job){
        json_object* states = json_object_new_array();
        JsonCvt_MovementList(&src->states, &states);
        json_object_object_add(*Job, "states", states);
    }

    static void JsonCvt_IntersectionStateList(IntersectionStateList_t* src, json_object** Job){
        int len = src->list.count;

        for(int i = 0; i<len; i++){
            json_object* IntersectionState_element = json_object_new_object();
            JsonCvt_IntersectionState(src->list.array[i], &IntersectionState_element);
            json_object_array_add(*Job, IntersectionState_element);

        }
    }

    static void JsonCvt_SPAT(SPAT_t* src, json_object** Job){

        json_object_object_add(*Job, "messageId", json_object_new_int(MESSAGE_ID_VALUE_SPAT));

        json_object* value = json_object_new_object();

        json_object* intersections = json_object_new_array();
        JsonCvt_IntersectionStateList(&src->intersections, &intersections);
        json_object_object_add(value, "intersections", intersections);

        json_object_object_add(*Job, "value", value);
    }

    static void MsgCvt_BSM(const char* json_string, MessageFrame_t* dst){
        json_object* msg = json_tokener_parse((const char*)json_string);

        (dst)->messageId = 20; // J2735 표준문서 PDF 파일 참조 basicSafetyMessage DSRCmsgID ::= 20 -- BSM, heartbeat msg
        (dst)->value.present = MessageFrame__value_PR_BasicSafetyMessage; // MessageFrame::value choice (asn1c)

        BasicSafetyMessage_t *ptrBsm = &dst->value.choice.BasicSafetyMessage;

        ptrBsm->coreData.id.buf = (uint8_t *)malloc(4);
        ptrBsm->coreData.id.size = 4;

        json_object* value = json_object_object_get(msg, "value");
        json_object* coreData = json_object_object_get(value, "coreData");
        json_object* id = json_object_object_get(coreData, "id");

        json_object* id_val_idx_0 = json_object_array_get_idx(id, 0);
        ptrBsm->coreData.id.buf[0] = json_object_get_int(id_val_idx_0);

        json_object* id_val_idx_1 = json_object_array_get_idx(id, 1);
        ptrBsm->coreData.id.buf[1] = json_object_get_int(id_val_idx_1);

        json_object* id_val_idx_2 = json_object_array_get_idx(id, 2);
        ptrBsm->coreData.id.buf[2] = json_object_get_int(id_val_idx_2);

        json_object* id_val_idx_3 = json_object_array_get_idx(id, 3);
        ptrBsm->coreData.id.buf[3] = json_object_get_int(id_val_idx_3);

        ptrBsm->coreData.msgCnt = json_object_get_int(json_object_object_get(coreData, "msgCnt"));               // (INPUT) <---- 매 BSM 전송마다 1씩 증가하는 값
        ptrBsm->coreData.secMark = json_object_get_int(json_object_object_get(coreData, "secMark"));              // (INPUT) <---- 전송 시점 UTC 시간 (초)
        ptrBsm->coreData.lat = json_object_get_int(json_object_object_get(coreData, "lat"));                  // (INPUT) <---- 현재 차량의 위치 (위도)
        ptrBsm->coreData.Long = json_object_get_int(json_object_object_get(coreData, "Long"));                 // (INPUT) <---- 현재 차량의 위치 (경도)
        ptrBsm->coreData.elev = json_object_get_int(json_object_object_get(coreData, "elev"));                 // (INPUT) <---- 현재 차량의 위치 (고도)

        json_object* accuracy = json_object_object_get(coreData, "accuracy");
        ptrBsm->coreData.accuracy.orientation = json_object_get_int(json_object_object_get(accuracy, "orientation")); // (INPUT) <---- 현재 차량의 위치 정확도 (SemiMajorAxisOrientation)
        ptrBsm->coreData.accuracy.semiMajor = json_object_get_int(json_object_object_get(accuracy, "semiMajor"));   // (INPUT) <---- 현재 차량의 위치 정확도 (SemiMajorAxisAccuracy)
        ptrBsm->coreData.accuracy.semiMinor = json_object_get_int(json_object_object_get(accuracy, "semiMinor"));   // (INPUT) <---- 현재 차량의 위치 정확도 (SemiMinorAxisAccuracy)
        
        ptrBsm->coreData.transmission = json_object_get_int(json_object_object_get(coreData, "transmission"));         // (INPUT) <---- 현재 차량의 변속기 상태
        ptrBsm->coreData.speed = json_object_get_int(json_object_object_get(coreData, "speed"));                // (INPUT) <---- 현재 차량의 속도
        ptrBsm->coreData.heading = json_object_get_int(json_object_object_get(coreData, "heading"));              // (INPUT) <---- 현재 차량의 진행 방향
        ptrBsm->coreData.angle = json_object_get_int(json_object_object_get(coreData, "angle"));                // (INPUT) <---- 현재 차량의 조향각 (Steering Wheel Angle)
        
        json_object* accelSet = json_object_object_get(coreData, "accelSet");
        ptrBsm->coreData.accelSet.lat = json_object_get_int(json_object_object_get(accelSet, "lat"));         // (INPUT) <---- 현재 차량의 가속도 정보 (Lateral Axis)
        ptrBsm->coreData.accelSet.Long = json_object_get_int(json_object_object_get(accelSet, "Long"));        // (INPUT) <---- 현재 차량의 가속도 정보 (Longitudinal Axis)
        ptrBsm->coreData.accelSet.vert = json_object_get_int(json_object_object_get(accelSet, "vert"));        // (INPUT) <---- 현재 차량의 가속도 정보 (Vertical Axis)
        ptrBsm->coreData.accelSet.yaw = json_object_get_int(json_object_object_get(accelSet, "yaw"));         // (INPUT) <---- 현재 차량의 가속도 정보 (Yaw rate)

        json_object* brakes = json_object_object_get(coreData, "brakes");
        ptrBsm->coreData.brakes.wheelBrakes.size = 1;
        ptrBsm->coreData.brakes.wheelBrakes.buf = (uint8_t *)malloc(1);
        ptrBsm->coreData.brakes.wheelBrakes.bits_unused = 3;
        *(ptrBsm->coreData.brakes.wheelBrakes.buf) = json_object_get_int(json_object_object_get(brakes, "wheelBrakes")); // (INPUT) <---- 현재 차량의 휠브레이크 상태

        ptrBsm->coreData.brakes.abs = json_object_get_int(json_object_object_get(brakes, "abs"));        // (INPUT) <---- 현재 차량의 ABS 브레이크 상태
        ptrBsm->coreData.brakes.auxBrakes = json_object_get_int(json_object_object_get(brakes, "auxBrakes"));  // (INPUT) <---- 현재 차량의 주차 브레이크 상태
        ptrBsm->coreData.brakes.brakeBoost = json_object_get_int(json_object_object_get(brakes, "brakeBoost")); // (INPUT) <---- 현재 차량의 브레이크 Boost 활성 상태
        ptrBsm->coreData.brakes.scs = json_object_get_int(json_object_object_get(brakes, "scs"));        // (INPUT) <---- 현재 차량의 SCS 상태
        ptrBsm->coreData.brakes.traction = json_object_get_int(json_object_object_get(brakes, "traction"));   // (INPUT) <---- 현재 차량의 TCS 상태

        json_object* size = json_object_object_get(coreData, "size");
        ptrBsm->coreData.size.length = json_object_get_int(json_object_object_get(size, "length")); // (INPUT) <---- 차량의 길이
        ptrBsm->coreData.size.width = json_object_get_int(json_object_object_get(size, "width"));  // (INPUT) <---- 차량의 너비

        ptrBsm->partII = NULL;   // <----- OPTION, not to use
        ptrBsm->regional = NULL; // <----- OPTION, not to use

    }

    static void MsgCvt_PVD(const char* json_string, MessageFrame_t* dst){

        json_object* msg = json_tokener_parse((const char*)json_string);

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


        json_object* value = json_object_object_get(msg, "value");
        json_object* probeID = json_object_object_get(value, "probeID");
        json_object* id = json_object_object_get(probeID, "id");
        json_object* jo_id_type = json_object_object_get(id, "type");
        int id_type = json_object_get_int(jo_id_type);
        json_object* jo_id_val = json_object_object_get(id, "val");

        if(id_type == 0){
            ptrPvd->probeID->id->choice.entityID.size = 4; 
            json_object* entityID = json_object_object_get(jo_id_val, "entityID");
            json_object* id_val_idx_0 = json_object_array_get_idx(entityID, 0);
            json_object* id_val_idx_1 = json_object_array_get_idx(entityID, 1);
            json_object* id_val_idx_2 = json_object_array_get_idx(entityID, 2);
            json_object* id_val_idx_3 = json_object_array_get_idx(entityID, 3);
            ptrPvd->probeID->id->choice.entityID.buf[0] = json_object_get_int(id_val_idx_0);      // (INPUT) <---- 할당된 대학별 ID 입력
            ptrPvd->probeID->id->choice.entityID.buf[1] = json_object_get_int(id_val_idx_1);      // (INPUT) <---- 할당된 대학별 ID 입력
            ptrPvd->probeID->id->choice.entityID.buf[2] = json_object_get_int(id_val_idx_2);      // (INPUT) <---- 할당된 대학별 ID 입력
            ptrPvd->probeID->id->choice.entityID.buf[3] = json_object_get_int(id_val_idx_3);      // (INPUT) <---- 할당된 대학별 ID 입력
        }
      
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



    }

};