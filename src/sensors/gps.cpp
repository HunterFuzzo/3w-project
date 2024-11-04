#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include "data_structures.h"

TinyGPSPlus gps;
SoftwareSerial ss(2, 3);

unsigned long startTime;
const unsigned long timeout = 5000;

void setupGps()
{
    Serial.begin(9600);
    ss.begin(9600);
    Serial.println("Initialisation du GPS");
}

bool gpsUpdated = false;

void logGpsData()
{
    startTime = millis();

    while (ss.available() > 0)
    {
        gps.encode(ss.read());
        if (gps.location.isUpdated())
        {
            Serial.print("---------- GPS ----------\n");
            gpsUpdated = true;
            Serial.print("Date: ");
            if (gps.date.day() < 10)
            {
                Serial.print("0");
            }
            Serial.print(gps.date.day());
            Serial.print("/");
            if (gps.date.month() < 10)
            {
                Serial.print("0");
            }
            Serial.print(gps.date.month());
            Serial.print("/");
            Serial.println(gps.date.year());
            Serial.print("Heure: ");
            if ((gps.time.hour() + 2) % 24 < 10)
            {
                Serial.print("0");
            }
            Serial.print((gps.time.hour() + 2) % 24);
            Serial.print(":");
            if (gps.time.minute() < 10)
            {
                Serial.print("0");
            }
            Serial.print(gps.time.minute());
            Serial.print(":");
            if (gps.time.second() < 10)
            {
                Serial.print("0");
            }
            Serial.println(gps.time.second());
            Serial.print("Latitude: ");
            Serial.println(gps.location.lat(), 6);
            Serial.print("Longitude: ");
            Serial.println(gps.location.lng(), 6);
            Serial.print("Altitude: ");
            Serial.println(gps.altitude.meters());
            Serial.print("-------------------------\n");
            delay(3000);
            startTime = millis();
        }
        if (millis() - startTime > timeout)
        {
            Serial.println("Erreur GPS");
            startTime = millis();
            gpsUpdated = false;
            break;
        }
    }
}



GpsData getGpsData()
{
    GpsData data = {0}; // Initialize the structure

    if (gps.location.isUpdated())
    {
        data.latitude = gps.location.lat();
        data.longitude = gps.location.lng();
        data.altitude = gps.altitude.meters();
        data.speed = gps.speed.kmph(); // Assuming you want speed in km/h
    }

    return data;
}
