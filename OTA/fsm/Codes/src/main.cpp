
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

int a=0,b=0,c=0,d=0;
int A,B,C,D;

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
void sevenseg(int a,int b,int c,int d,int e,int f,int g);

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
    pinMode(13,OUTPUT);     //13th pin as clk and 15,17,19,21 as input pins and 16,18,20,22  as output pins
    pinMode(15,INPUT);
    pinMode(17,INPUT);
    pinMode(19,INPUT);
    pinMode(21,INPUT);
    pinMode(16,OUTPUT);
    pinMode(18,OUTPUT);
    pinMode(20,OUTPUT);
    pinMode(22,OUTPUT);
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  digitalWrite(13,HIGH);
  a=digitalRead(15);
  b=digitalRead(17);
  c=digitalRead(19);
  d=digitalRead(21);
  delay(1000);
  A  = (!a)&&(!b)&&(!c)&&(!d) || (a&&d);
  B =  (a)&&(!d)||(b&&d)||(b&&c);
  C = (c&&d)||(a&&(!d))||(b&&(!c)&&(!d));
  D = (!d);  
  digitalWrite(16,A);
  digitalWrite(18,B);
  digitalWrite(20,C);
  digitalWrite(22,D);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
}


