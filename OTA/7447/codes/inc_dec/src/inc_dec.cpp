
//Code by GVV Sharma
//April 29, 2022
//https://www.gnu.org/licenses/gpl-3.0.en.html
//
//Seven segment diplay OTA
//
//----------------------Skeleton Code--------------------//

//           LCD interfacing With ESP32     //


#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// set the LCD number of columns and rows
 
//    Can be client or even host   //
#ifndef STASSID
#define STASSID "ssid"  // Replace with your network credentials
#define STAPSK  "password"  
#endif


const char* ssid = STASSID;
const char* password = STAPSK;




void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
int Z=0,Y=0,X=0,W=1;	//input
int D,C,B,A;

void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(13, A); //LSB
  digitalWrite(15, B); 
  digitalWrite(17, C); 
  digitalWrite(19, D); //MSB

}

void setup(){
  OTAsetup();
    pinMode(13, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(19, OUTPUT);           
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  A=!W && !Z;
  B=(W &&!X && !Z) || (!W && X && !Z);
  C=(!W && Y && !Z) || (!X && Y && !Z) || (W && X && !Y && !Z);
  D = (W && X && Y && !Z)||(!W && !X && !Y && Z);
  
disp_7447(D,C,B,A); 
}


