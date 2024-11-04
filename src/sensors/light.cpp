#include "sensors/light.h"
#include <Arduino.h>

#define LIGHT_SENSOR_PIN A0

void setupLightSensor()
{
    pinMode(LIGHT_SENSOR_PIN, INPUT);
}

int readLightSensor()
{
    return analogRead(LIGHT_SENSOR_PIN);
}

void logLightSensor()
{
    int lightSensorValue = readLightSensor();
    Serial.print("Light Sensor Value: ");
    Serial.println(lightSensorValue);
    delay(2000);
}



LightSensorData getLightSensorData() {
    LightSensorData data = {0}; // Initialize the structure
    data.lightLevel = readLightSensor(); // Read the light sensor value
    return data; // Return the populated structure
}
