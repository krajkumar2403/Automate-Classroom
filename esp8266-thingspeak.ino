#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "raj"; //wifi ssid
const char* pass = "12345678"; //wifi password

WiFiClient client;
//channel number and API key for channel are available in thingspeak website
unsigned long channelNo = 1632590;
const char* APIKey = "MMAXYT2IAHYMF8FR";

int in=2;
int out=0;
int count=0;

//declare pins in esp8266 wifi module and connect to wifi and thingspeak
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
  ThingSpeak.begin(client); 
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(vol,OUTPUT);
}

void loop() {
  
  //detect outside to inside movement, increment count and display count on the thingspeak website
  if (!digitalRead(in)){
      count++;
      Serial.print("Count: ");
      Serial.println(count);
      ThingSpeak.writeField(channelNo,1,count,APIKey);
      delay(100);
  }
  
  //detect inside to ouside movement decrement count and display count on the thingspeak website
  if (!digitalRead(out)){
      count--;
      Serial.print("Count: ");
      Serial.println(count);
      ThingSpeak.writeField(channelNo,1,count,APIKey);
      delay(100);
  }
  
  //if nobody in the room, then power supply is off
  if (count==0)
    vol=0;
  else
    vol=1;
}
