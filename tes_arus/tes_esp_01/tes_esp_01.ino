#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3); // RX, TX

ESP8266 wifi(&Serial1);   

char auth[] = "2jkuXfLvPRj-7YSHp9I3Qw6ZhmN3Xqgt";
char ssid[] = "POJOK SENJA";
char pass[] = "ciumdulu";

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8080);
}

void loop() {
    Blynk.virtualWrite(V1, String(20));
    Blynk.virtualWrite(V2, String(21));
    Blynk.virtualWrite(V3, String(23));
    Blynk.virtualWrite(V4, String(45));
  // put your main code here, to run repeatedly:
   Blynk.run(); 
}
