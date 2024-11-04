#include <Arduino.h>
#include "utils/log_data.h"

void logData(const Data& data) {
    // Print GPS Data
    Serial.println("GPS Data:");
    Serial.print("- Latitude: ");
    Serial.println(data.gpsData.latitude);
    Serial.print("- Longitude: ");
    Serial.println(data.gpsData.longitude);
    Serial.print("- Altitude: ");
    Serial.println(data.gpsData.altitude);
    Serial.print("- Speed: ");
    Serial.println(data.gpsData.speed);
    Serial.println(); // Blank line

    // Print THP Data
    Serial.println("THP Data:");
    Serial.print("- Temperature: ");
    Serial.println(data.thpData.temperature);
    Serial.print("- Humidity: ");
    Serial.println(data.thpData.humidity);
    Serial.print("- Pressure: ");
    Serial.println(data.thpData.pressure);
    Serial.println(); // Blank line

    // Print Light Sensor Data
    Serial.println("Light Sensor Data:");
    Serial.print("- Light Level: ");
    Serial.println(data.lightSensorData.lightLevel);
    Serial.println(); // Blank line

    // Print RTC Data
    Serial.println("RTC Data:");
    Serial.print("- Year: ");
    Serial.println(data.rtcData.year);
    Serial.print("- Month: ");
    Serial.println(data.rtcData.month);
    Serial.print("- Day: ");
    Serial.println(data.rtcData.day);
    Serial.print("- Hour: ");
    Serial.println(data.rtcData.hour);
    Serial.print("- Minute: ");
    Serial.println(data.rtcData.minute);
    Serial.print("- Second: ");
    Serial.println(data.rtcData.second);
    Serial.println("-------------------------");
}
