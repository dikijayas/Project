#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#include <DS3231.h> //mengincludekan library DS3231
 
DS3231  rtc(SDA, SCL); // inisialisasi penggunaan i2c
 
void setup()
{
  Serial.begin(115200); //set komunikasi baut serial monitor pada 115200
  rtc.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ;  // Address 0x3D for 128x64
  
  //setting pertama download program
  //rtc.setDate(7, 12, 2019);   //mensetting tanggal 24 juni 2019
  //rtc.setTime(22, 37, 10);     //menset jam 20:15:10
  //rtc.setDOW(6);     //menset hari "Selasa"
 
//setelah didownload awal selesai, download kedua dengan memberi tanda komen "//"
}
 
void loop()
{
  display.clearDisplay();
  
  Serial.print(rtc.getDOWStr()); //prosedur pembacaan hari
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr()); //prosedur pembacaan tanggal
  Serial.print(" -- ");
 
  Serial.println(rtc.getTimeStr()); //prosedur pembacaan waktu
  Serial.print(rtc.getTemp());

//OLED
  //Hari
  display.setCursor(50,10);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.println(rtc.getDOWStr());
  //Waktu
  display.setCursor(20,20); 
  display.setTextColor(BLACK,WHITE);
  display.setTextSize(2);
  display.println(rtc.getTimeStr());
  display.setCursor(8,20); 
  display.setTextColor(BLACK,WHITE);
  display.setTextSize(2);
  display.println(" ");
  display.setCursor(115,20); 
  display.setTextColor(BLACK,WHITE);
  display.setTextSize(2);
  display.println(" ");
  
  
  //Suhu
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setCursor(50,40);
  display.println(rtc.getTemp());
  display.setCursor(85,40);
  display.println("C");
  //Tanggal
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setCursor(40,50);
  display.println(rtc.getDateStr());
  
  display.display(); 
  delay (1000); //waktu tunda 1 detik per cycle
}
