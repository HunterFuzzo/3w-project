#include <Wire.h>
#include <RTClib.h>
#include <Arduino.h>
#include "data_structures.h"

RTC_DS1307 clock;

void setupRtc()
{
    Serial.begin(9600);

    // Initialiser le module RTC
    if (!clock.begin())
    {
        Serial.println("RTC introuvable !");
        while (1)
            ; // Bloque l'exécution si le RTC est absent
    }

    // Si l'horloge n'est pas en marche, on initialise l'heure
    if (!clock.isrunning())
    {
        Serial.println("RTC is NOT running, setting the time!");
        // Initialiser l'heure (Année, Mois, Jour, Heure, Minute, Seconde)
        clock.adjust(DateTime(2013, 1, 19, 15, 28, 30)); // Date initiale donnée
    }
}

void logRtcData()
{
    // Récupérer l'heure et la date actuelles
    DateTime now = clock.now();

    // Afficher l'heure au format HH:MM:SS
    Serial.print(now.hour(), DEC);
    Serial.print(":");
    Serial.print(now.minute(), DEC);
    Serial.print(":");
    Serial.print(now.second(), DEC);
    Serial.print("    ");

    // Afficher la date au format JJ/MM/AAAA
    Serial.print(now.day(), DEC);
    Serial.print("/");
    Serial.print(now.month(), DEC);
    Serial.print("/");
    Serial.print(now.year(), DEC);
    Serial.print(" ");

    // Afficher le jour de la semaine
    static const char *jours[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    Serial.print(jours[now.dayOfTheWeek()]);

    Serial.println();
}



RtcData getRtcData() {
    RtcData data = {0}; // Initialize the structure

    DateTime now = clock.now();
    data.year = now.year();
    data.month = now.month();
    data.day = now.day();
    data.hour = now.hour();
    data.minute = now.minute();
    data.second = now.second();

    return data;
}
