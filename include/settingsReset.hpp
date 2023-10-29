void settingResetWiFi(){
    //-----------------General---------------
    strlcpy(id, "adminesp32", sizeof(id));
    bootCount = 0;
    //----------------Cliente----------------
    wifi_staticIP = true;
    strlcpy(wifi_ssid, "Telecentro-3626", sizeof(wifi_ssid));
    strlcpy(wifi_passw, "RWZJZWZWGJZX", sizeof(wifi_passw));
    //strlcpy(wifi_ip_static, "192.168.0.70", sizeof(wifi_ip_static));
    strlcpy(wifi_gateway, "192.168.0.1", sizeof(wifi_gateway));
    strlcpy(wifi_subnet, "255.255.255.0", sizeof(wifi_subnet));
    strlcpy(wifi_primaryDNS, "8.8.8.8", sizeof(wifi_primaryDNS));
    strlcpy(wifi_secondaryDNS, "8.8.4.4", sizeof(wifi_secondaryDNS));
    //---------------AP----------------------------------
    ap_accessPoint = false;
    strlcpy(ap_nameap, deviceID().c_str(), sizeof(ap_nameap));
    strlcpy(ap_passwordap, "adminesp32", sizeof(ap_passwordap));
    ap_canalap = 9;
    ap_hiddenap = false;
    ap_connetap = 4;
}

//------------------------------------------------
// Valores por defecto parametros MQTT
//-------------------------------------------------

void settingsResetMQTT(){
    //define config por defecto del equipo conexion mqtt
    strlcpy(mqtt_user, "cuba_iot", sizeof(mqtt_user));
    strlcpy(mqtt_passw, "cuba_iot", sizeof(mqtt_passw));
    strlcpy(mqtt_server, "cubaelectronica.com", sizeof(mqtt_server));
    strlcpy(mqtt_id, deviceID().c_str(), sizeof(mqtt_id));
    mqtt_time = 60000;
    mqtt_port = 1883;
    mqtt_enable = true;
}

//------------------------------------------------
// Valores por defecto parametros Relay
//-------------------------------------------------

void settingResetRelay(){
    Relay01_status = LOW;
    Relay02_status = LOW;
}