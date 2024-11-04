// ModesHandler.h
#ifndef MODES_HANDLER_H
#define MODES_HANDLER_H

#include <ChainableLED.h>
#include <string.h>

// LED and Button Configuration
#define NUM_LEDS 1
#define BUTTON_RED_PIN 4
#define BUTTON_GREEN_PIN 3
#define LED_PIN_1 7
#define LED_PIN_2 8

// Timing Constants
#define TIMEOUT 5000
#define BUTTON_PRESSED_TIME 3000

// Color Definitions
#define GREEN 0, 255, 0
#define YELLOW 255, 255, 0
#define BLUE 0, 0, 255
#define ORANGE 255, 128, 0
#define BLACK 0, 0, 0

// Mode Flags

// LED and Mode Variables

enum Mode
{
    STANDARD,
    CONFIGURATION,
    MAINTENANCE,
    ECONOMIC,
    OFF
};

// Function declarations
void setMode(Mode mode);
void setupLeds();
bool isButtonPressedLong(int buttonPin, unsigned long duration);
void handleStartup();
void handleStandardMode();
void handleEconomicMode();
void handleMaintenanceMode();
void handleConfigurationMode();
void setupConfig();

#endif