/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e2ba8b8f3a114645843818766a45820f";

// Your WiFi credentials.
// Set password to "" for open networks.
Servo servo ;
Servo servo2 ;
Servo servo3 ;
char ssid[] = "iPhone aldhofransnanda";
char pass[] = "inalganteng55";

void setup()
{
  // Debug console
  Serial.begin(9600);
  Serial.println("diki jaya" ) ;
  Blynk.begin(auth, ssid, pass);
  servo.attach(4) ;
  servo2.attach(3) ;
  servo3.attach(2) ;
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V7) {
  servo.write(param.asInt()) ;
}
BLYNK_WRITE(V0) {
  servo.write(0) ;

}
BLYNK_WRITE(V1) {
  servo.write(30) ;
}
BLYNK_WRITE(V2) {
  servo2.write(0) ;
}
BLYNK_WRITE(V3) {
  servo2.write(30) ;
}
BLYNK_WRITE(V4) {
  servo3.write(0) ;
}
BLYNK_WRITE(V5 ) {
  servo3.write(30) ;
}

