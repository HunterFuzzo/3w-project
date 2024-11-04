// SetMode.cpp
#include "utils/mode_handler.h"
#include <Arduino.h>

bool ecoModeEnabled;
bool maintenanceModeEnabled;
bool standardModeEnabled;
bool configModeEnabled;
bool hasEnteredMode;

char previousMode[256];

ChainableLED leds(LED_PIN_1, LED_PIN_2, NUM_LEDS);
Mode currentMode = OFF;

void handleStartup()
{
    if (hasEnteredMode)
        return;

    if (digitalRead(BUTTON_RED_PIN) == LOW)
    {
        currentMode = CONFIGURATION;
        setMode(currentMode);
        hasEnteredMode = true;
        return;
    }

    if (digitalRead(BUTTON_GREEN_PIN) == LOW)
    {
        currentMode = STANDARD;
        setMode(currentMode);
        hasEnteredMode = true;
        return;
    }
}

void setMode(Mode mode)
{
    switch (mode)
    {
    case OFF:
        leds.setColorRGB(0, BLACK);
        break;
    case STANDARD:
        leds.setColorRGB(0, GREEN);
        Serial.println("Mode: Standard");
        break;
    case CONFIGURATION:
        leds.setColorRGB(0, YELLOW);
        Serial.println("Mode: Configuration");
        break;
    case MAINTENANCE:
        leds.setColorRGB(0, ORANGE);
        Serial.println("Mode: Maintenance");
        break;
    case ECONOMIC:
        leds.setColorRGB(0, BLUE);
        Serial.println("Mode: Économique");
        break;
    }
}

void setupConfig()
{
    switch (currentMode)
    {
    case STANDARD:
        handleStandardMode();
        break;
    case ECONOMIC:
        handleEconomicMode();
        break;
    case MAINTENANCE:
        handleMaintenanceMode();
        break;
    case CONFIGURATION:
        handleConfigurationMode();
        break;
    default:
        break;
    }
}

void setupLeds()
{
    Serial.begin(9600);
    pinMode(BUTTON_RED_PIN, INPUT_PULLUP);
    pinMode(BUTTON_GREEN_PIN, INPUT_PULLUP);
    setMode(OFF);
}

bool isButtonPressedLong(int buttonPin, unsigned long duration)
{
    unsigned long startTime = millis();
    while (digitalRead(buttonPin) == LOW)
    {
        if (millis() - startTime > duration)
        {
            return true;
        }
    }
    return false;
}

void handleEconomicMode()
{
    if (isButtonPressedLong(BUTTON_GREEN_PIN, BUTTON_PRESSED_TIME))
    {
        currentMode = STANDARD;
        setMode(currentMode);
        standardModeEnabled = false;
    }
    else if (isButtonPressedLong(BUTTON_RED_PIN, BUTTON_PRESSED_TIME))
    {
        strcpy(previousMode, "economic");
        currentMode = MAINTENANCE;
        setMode(currentMode);
        maintenanceModeEnabled = false;
    }
}

void handleConfigurationMode()
{
    unsigned long startTime = millis();
    while (millis() - startTime < TIMEOUT)
        ; // Attente jusqu'à expiration du délai
    currentMode = STANDARD;
    setMode(currentMode);
}

void handleStandardMode()
{
    if (isButtonPressedLong(BUTTON_GREEN_PIN, BUTTON_PRESSED_TIME))
    {
        currentMode = ECONOMIC;
        setMode(currentMode);
        ecoModeEnabled = false;
    }
    if (isButtonPressedLong(BUTTON_RED_PIN, BUTTON_PRESSED_TIME))
    {
        strcpy(previousMode, "standard");
        currentMode = MAINTENANCE;
        setMode(currentMode);
        maintenanceModeEnabled = false;
    }
}

void handleMaintenanceMode()
{
    if (strcmp(previousMode, "standard") == 0 && isButtonPressedLong(BUTTON_RED_PIN, BUTTON_PRESSED_TIME))
    {
        currentMode = STANDARD;
        setMode(currentMode);
        standardModeEnabled = false;
    }
    else if (strcmp(previousMode, "economic") == 0 && isButtonPressedLong(BUTTON_RED_PIN, BUTTON_PRESSED_TIME))
    {
        currentMode = ECONOMIC;
        setMode(currentMode);
        ecoModeEnabled = false;
    }
}
