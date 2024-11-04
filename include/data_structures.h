#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
//TODO: lean out the types
struct GpsData {
    float latitude;
    float longitude;
    float altitude;
    float speed;
};

struct ThpData {
    float temperature;
    float humidity;
    float pressure;
};

struct LightSensorData {
    int lightLevel; // Example: light intensity
};

struct RtcData {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct Data {
    GpsData gpsData;
    ThpData thpData;
    LightSensorData lightSensorData;
    RtcData rtcData;
};

#endif // DATA_STRUCTURES_H
