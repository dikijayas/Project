#include <TinyGPS++.h>
#include <SoftwareSerial.h>
SoftwareSerial serial_gps(3,2); //RX,TX
TinyGPSPlus gps;
double latitude , longitude;
 
void setup() {
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");
}
 
void loop() {
  
  while(serial_gps.available()) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    String link = "www.google.com/maps/place/" + String(latitude, 6) + "," + String(longitude,6) ;
    Serial.println(link);
    Serial.print ("latitude : ") ;
    Serial.println(latitude, 6);
    Serial.print ("longitude: ") ;
    Serial.println(longitude, 6);
    Serial.print ("Satelit Count: ") ;
    Serial.println (gps.satellites.value()) ;
    Serial.print ("Altitude feed: ") ;
    Serial.println (gps.altitude.feet()) ;
    Serial.println ("") ;
    delay(5000);
    
  }
  
}
