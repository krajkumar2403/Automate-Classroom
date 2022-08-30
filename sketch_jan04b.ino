#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "raj";
const char* pass = "12345678";

WiFiClient client;
unsigned long channelNo = 1632590;
const char* APIKey = "MMAXYT2IAHYMF8FR";

int in=2;
int out=0;
int count=0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
  ThingSpeak.begin(client); 
  pinMode(in, INPUT);
  pinMode(out, INPUT);
}

void loop() {
  
  if (!digitalRead(in)){
      count++;
      Serial.print("Count: ");
      Serial.println(count);
      ThingSpeak.writeField(channelNo,1,count,APIKey);
      delay(100);
  }

  if (!digitalRead(out)){
      count--;
      Serial.print("Count: ");
      Serial.println(count);
      ThingSpeak.writeField(channelNo,1,count,APIKey);
      delay(100);
  }

}
