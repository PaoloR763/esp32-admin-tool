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
#include "esp32_mqtt.hpp"

//---------------------------------------------------------------------------------------------------------------
// Setup
//---------------------------------------------------------------------------------------------------------------

void setup() {

    
    Serial.begin(115200);                   //Velocidad puerto serial   
    setCpuFrequencyMhz(240);                //CPU Freq
    log("\n Info: Iniciando Setup");        //Inicio el log por serial
    settingPines();                         //Configurar los pines de salida
    if(!SPIFFS.begin(true)){                //Inicio del SPIFF
        log(F("Error: Fallo la inicializacion del SPIFFS"));
        while(true);
    }
    settingsReadRelay();                    //Lee los estados de los relays
    setOnOffSingle(RELAY1,Relay01_status);    // Paso estados a los pines Relays
    setOnOffSingle(RELAY2,Relay02_status);
    settingsReadWiFi();                     //Lee configuracion WiFi
    WiFi.disconnect(true);                  //Si hay wifi, lo desconecto y espero 1 seg
    delay(1000);
    wifi_setup();                           //Setup del Wifi
    settingsReadMQTT();                     //lee la configuracion MQTT

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
    }else if(wifi_mode == WIFI_AP){
        wifiAPLoop();
    }

    //-----------------------------------------------------------------------------------------------------------------
    // MQTT
    //-----------------------------------------------------------------------------------------------------------------
    if((WiFi.status() == WL_CONNECTED) && (wifi_mode == WIFI_STA)){
        if(mqtt_server != 0){
            mqttLoop();
            if(mqttclient.connected()){
                if(millis() - lastMsg > mqtt_time){
                    lastMsg = millis();
                    mqtt_publish();
                }
            }
        }
    }

    
    
}
