#include "sensors/thp.h"
#include <Wire.h>
#include <Adafruit_Sensor.h> // Add this line
#include <Adafruit_BME280.h> // Ensure this line is present

Adafruit_BME280 bme; // Create an object of the BME280 class

void setupSensor() {
    if (!bme.begin(0x76)) { // Change 0x76 to 0x77 if that's your sensor's I2C address
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1); // Loop forever
    }
}

void logThpSensorData() {
    // Read temperature, humidity, and pressure
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() / 100.0F; // Convert to hPa

    // Print values to serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");
}



ThpData getThpSensorData() {
    ThpData data = {0}; // Initialize the structure

    data.temperature = bme.readTemperature();
    data.humidity = bme.readHumidity();
    data.pressure = bme.readPressure();

    return data;
}
