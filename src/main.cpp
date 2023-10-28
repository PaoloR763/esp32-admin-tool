//---------------------------------------------------------------------------------------------------------------
//  Librerias
//----------------------------------------------------------------------------------------------------------------
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
//---------------------------------------------------------------------------------------------------------------
//Archivos -hpp - Fragmentar Codigo
//---------------------------------------------------------------------------------------------------------------
#include "settings.hpp"
#include "functions.hpp"
#include "settingsReset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "esp32_wifi.hpp"

//---------------------------------------------------------------------------------------------------------------
// Setup
//---------------------------------------------------------------------------------------------------------------

void setup() {

    
    Serial.begin(115200);               //Velocidad puerto serial   
    setCpuFrequencyMhz(240);            //CPU Freq
    log("\n Info: Iniciando Setup");     //Inicio el log por serial
    settingPines();                     //Configurar los pines de salida
    if(!SPIFFS.begin(true)){                //Inicio del SPIFF
        log(F("Error: Fallo la inicializacion del SPIFFS"));
        while(true);
    }
    settingsReadWiFi();                 //Lee configuracion WiFi
    WiFi.disconnect(true);             //Si hay wifi, lo desconecto y espero 1 seg
    delay(1000);
    wifi_setup();

}

//-----------------------------------------------------------------------------------------------------------------
// Loop Principal Nucleo 0
//-----------------------------------------------------------------------------------------------------------------
void loop() {
    yield();
//-----------------------------------------------------------------------------------------------------------------
// WIFI
//-----------------------------------------------------------------------------------------------------------------
    if(wifi_mode == WIFI_STA){
        wifiLoop();
    }
    
    if(wifi_mode == WIFI_AP){
        wifiAPLoop();
    }
}
