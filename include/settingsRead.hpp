//--------------------------------------------------
// Valores por defecto parametros wifi
//--------------------------------------------------

boolean settingsReadWiFi(){

    StaticJsonDocument<500> jsonConfig;                 //Se crea un doc Json con 500bytes
    File file = SPIFFS.open("/SettingWifi.json","r");   //Abrimos el archivo SettingWifi    
    if(deserializeJson(jsonConfig, file)){
        //Si falla la lectura inicia valores por defecto
        settingResetWiFi();
        log("Error: Fallo la lectura de la configuracion WiFi, tomando valores por defecto");
        return false;
    }else{
        //------------------------------General--------------------
        strlcpy(id, jsonConfig["id"], sizeof(id));
        bootCount = jsonConfig["boot"];

        //------------------Cliente----------------------
        wifi_staticIP = jsonConfig["wifi_staticIP"];
        strlcpy(wifi_ssid, jsonConfig["wifi_ssid"], sizeof(wifi_ssid));
        strlcpy(wifi_passw, jsonConfig["wifi_passw"], sizeof(wifi_passw));
        strlcpy(wifi_ip_static, jsonConfig["wifi_ip_static"], sizeof(wifi_ip_static));
        strlcpy(wifi_gateway, jsonConfig["wifi_gateway"], sizeof(wifi_gateway));
        strlcpy(wifi_subnet, jsonConfig["wifi_subnet"], sizeof(wifi_subnet));
        strlcpy(wifi_primaryDNS, jsonConfig["wifi_primaryDNS"], sizeof(wifi_primaryDNS));
        strlcpy(wifi_secondaryDNS, jsonConfig["wifi_secondaryDNS"], sizeof(wifi_secondaryDNS));
        //-------------Ap----------------------------
        ap_accessPoint = jsonConfig["ap_accessPoint"];
        strlcpy(ap_nameap, jsonConfig["ap_nameap"], sizeof(ap_nameap));
        strlcpy(ap_passwordap, jsonConfig["ap_passwordap"], sizeof(ap_passwordap));
        ap_canalap = jsonConfig["ap_canalap"];
        ap_hiddenap = jsonConfig["ap_hiddenap"];
        ap_connetap = jsonConfig["ap_connetap"];
        file.close();
        log("Info: Lectura configuracion WiFi correcta");
        return true;
    }
}


//--------------------------------------------------
// Leer configuraciones de los parametros MQTT
//--------------------------------------------------

boolean settingsReadMQTT(){
    //LEE LA CONFIG MQTT
    StaticJsonDocument<500> jsonConfig;

    File file = SPIFFS.open(F("/settingmqtt.json"), "r");
    if(deserializeJson(jsonConfig, file))
    {
        //Si falla la lectura asume valores por defecto
        settingsResetMQTT();
        log(F("Error: Fallo la lectura de la configuracion MQTT, tomando valores por defecto"));
        return false;
    }
    else{
        //si lee el archivo
        strlcpy(mqtt_user, jsonConfig["mqtt_user"], sizeof(mqtt_user));
        strlcpy(mqtt_passw, jsonConfig["mqtt_passw"], sizeof(mqtt_passw));
        strlcpy(mqtt_server, jsonConfig["mqtt_server"], sizeof(mqtt_server));
        strlcpy(mqtt_id, jsonConfig["mqtt_id"], sizeof(mqtt_id));
        mqtt_time = jsonConfig["mqtt_time"];
        mqtt_port = jsonConfig["mqtt_port"];
        mqtt_enable = jsonConfig["mqtt_enable"];
        file.close();
        log(F("Info: Lectura de configuracion MQTT correcta"));
        return true;
    }
}

//--------------------------------------------------------------------
// Leer los estados de los relays
//--------------------------------------------------------------------

boolean settingsReadRelay(){
    StaticJsonDocument<200> jsonConfig;
    File file = SPIFFS.open("/settingrelay.json", "r");
    if(deserializeJson(jsonConfig, file)){
        //Si falla la lectura inicia valores por defecto
        settingResetRelay();
        log("Error: Fallo la lectura del estados de los Relays, tomando valores por defecto");
        return false;
    }else{
        Relay01_status = jsonConfig["Relay01_status"];
        Relay02_status = jsonConfig["Relay02_status"];
        file.close();
        log("Info: Lectura de los relay correcta");
        return true;
    }
}
