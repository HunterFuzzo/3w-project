#include <Arduino.h>
#include "sensors/gps.h"
#include "sensors/thp.h"
#include "sensors/light.h"
#include "sensors/rtc.h"

Data getData() {
    Data logData;
    logData.gpsData = getGpsData();
    logData.thpData = getThpSensorData();
    logData.lightSensorData = getLightSensorData();
    logData.rtcData = getRtcData();
    return logData;
}
