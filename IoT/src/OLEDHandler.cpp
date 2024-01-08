#include "OLEDHandler.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

void setupOLED()
{
  Serial.println("OLED FeatherWing test");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");
  // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting to SSID\n'adafruit':");
  display.print("connected!");
  display.println("IP: 192.168.0.1");
  display.println("Sending val #0");
  display.setCursor(0, 0);
  display.display(); // actually display all of the above
}

void updateOLED()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Temperature: ");
  display.print(getTemperature());
  display.println(" C");
  display.print("Humidity: ");
  display.print(getHumidity());
  display.println("%");
  display.print("Moisture: ");
  display.println(getMoisture());
  display.display();
}