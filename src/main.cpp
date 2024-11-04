#include <ChainableLED.h>
#include <Arduino.h>
#include "sensors/gps.h"
#include "sensors/thp.h"
#include "sensors/light.h"
#include "sensors/rtc.h"
#include "utils/mode_handler.h"
#include "utils/log_data.h"

void setup()
{
  Serial.begin(9600);
  setupGps();
  setupSensor();
  setupLightSensor();
  setupRtc();
  setupLeds();
}

void loop()
{
  handleStartup(); //TODO: reorganiser ces deux fonctions
  setupConfig();
  Data data = getData();
  logData(data);
  //delay(3000);
}


// next steps:
// sd
// specificités des modes
// gestion des erreurs avec fonction throw_error(ERROR_TYPE)
// deux types d'erreurs, mal connecté et aussi juste valeures anormales?
// make exe
// maybe dashboard??
// use .txt? does it really take more space?
// adapter les types
