//---------------------------------------------------------------------
//Definiciones
//---------------------------------------------------------------------
#define REALY1  27               // GPIO27 salida relay 1
#define RELAY2  26               // GPIO26 salida relay 2
#define WIFILED 12
#define MQTTLED 13

//--------------------------------------------------------------------
// Version de HW
//---------------------------------------------------------------------

#define HW "ADMINESP32 v1 00000000" //Version del hw

//--------------------------------------------------------------------
// Apartado WiFi
//---------------------------------------------------------------------

boolean wifi_staticIP;           //Uso de IP estatico
char    wifi_ssid[30];
char    wifi_passw[30];
char    wifi_ip_static[15];
char    wifi_gateway[15];
char    wifi_subnet[15];
char    wifi_primaryDNS[15];
char    wifi_secondaryDNS[15];

//--------------------------------------------------------------------
//Configuraciones Generales
//--------------------------------------------------------------------
char    id[30];                 //ID del dispositivo
int     bootCount;               //Numero de reinicios

//--------------------------------------------------------------------
// Configuraciones AP
//--------------------------------------------------------------------

boolean ap_accessPoint;            //Uso Modo AP
char    ap_nameap[31];                //SSID AP
char    ap_passwordap[63];            //Password AP
int     ap_canalap;                    //Canal AP
int     ap_hiddenap;                   //Es visible o no el AP (0: Visible - 1: Oculto)
int     ap_connetap;                   // Numero de conexiones en el AP

// Otras
uint8_t ip[4];                  //Variable funcion convertir string a IP