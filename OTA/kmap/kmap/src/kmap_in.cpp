

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
#define STASSID "SSID"  // Replace with your network credentials
#define STAPSK  "PASSWORD"
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
int Z=0,Y=0,X=0,W=0;
int D,C,B,A;
void sev7447(int D,int C,int B,int A) // connect a,b,c,d to 7447
{ 
	digitalWrite(14,A);
	digitalWrite(16,B);
	digitalWrite(20,C);
	digitalWrite(22,D);
}
void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  pinMode(14,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(20,OUTPUT);
  pinMode(22,OUTPUT);
  
  //-------------------//
    
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  
  //-------------------//
  A=(!Z&&!W)||(!Y&&!X&&!W);
  B=(!Z&&!X&&W)||(!Z&&X&&!W);
  C=(!Z&&Y&&!W)||(!Z&&!Y&&X&&W)||(!Z&&Y&&!X);
  D=(Z&&!Y&&!X&&!W)||(!Z&&X&&Y&&W);

  sev7447(D,C,B,A);
}




