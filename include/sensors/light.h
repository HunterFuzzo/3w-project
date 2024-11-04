#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "utils/get_data.h"

void setupLightSensor();
int readLightSensor();
void logLightSensor();
LightSensorData getLightSensorData(); // Declaration for the getLightSensorData function

#endif // LIGHTSENSOR_H
