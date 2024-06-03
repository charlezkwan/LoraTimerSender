#include "heltec.h"
#include "Arduino.h"
#include <Wire.h>
#include <DS3231.h>

//rotate only for GEOMETRY_128_64
SSD1306Wire oleddisplay(0x3c, SDA_OLED, SCL_OLED, RST_OLED);
RTClib myRTC;
void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) //Vext default OFF
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}

void setup() {

  delay(500);
  Serial.println("Nano Ready!");
  VextON();
  delay(100);

  oleddisplay.init();
  oleddisplay.clear();
  oleddisplay.display();
  
  oleddisplay.setContrast(255);
  
  oleddisplay.setTextAlignment(TEXT_ALIGN_CENTER);
  oleddisplay.clear();
  oleddisplay.display();
  oleddisplay.screenRotate(ANGLE_0_DEGREE);
  oleddisplay.setFont(ArialMT_Plain_16);
  oleddisplay.drawString(64, 32-16/2, "ROTATE_0");
  oleddisplay.display();
  delay(2000);

  oleddisplay.clear();
  oleddisplay.display();
  oleddisplay.screenRotate(ANGLE_90_DEGREE);
  oleddisplay.setFont(ArialMT_Plain_10);
  oleddisplay.drawString(32, 64-10/2, "ROTATE_90");
  oleddisplay.display();
  delay(2000);

  oleddisplay.clear();
  oleddisplay.display();
  oleddisplay.screenRotate(ANGLE_180_DEGREE);
  oleddisplay.setFont(ArialMT_Plain_16);
  oleddisplay.drawString(64, 32-16/2, "ROTATE_180");
  oleddisplay.display();
  delay(2000);

  oleddisplay.clear();
  oleddisplay.display();
  oleddisplay.screenRotate(ANGLE_270_DEGREE);
  oleddisplay.setFont(ArialMT_Plain_10);
  oleddisplay.drawString(32, 64-10/2, "ROTATE_270");
  oleddisplay.display();
  delay(2000);
  Serial.begin(115200);
  Wire.begin();
}

void loop() { 
      delay(1000);
    
    DateTime now = myRTC.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    char str[20];
    sprintf(str,"%d", now.hour());
    sprintf(str + strlen(str),":");
    sprintf(str + strlen(str),"%d", now.minute());
    sprintf(str + strlen(str),":");
    sprintf(str + strlen(str),"%d", now.second());
    oleddisplay.clear();
    oleddisplay.display();
    oleddisplay.screenRotate(ANGLE_0_DEGREE);
    oleddisplay.setFont(ArialMT_Plain_16);
    oleddisplay.drawString(64, 32-16/2, str);
    oleddisplay.display();
}