#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int buttonPin = 2;
Adafruit_SSD1306 display(-1);
int buttonState = 0;

void setup() {
  // ------- Do not modify this section of code ------
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  // Clear the buffer.
  display.clearDisplay();


  pinMode(buttonPin, INPUT);
  // --------------------------------------------------
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int val = analogRead(1) / 128;
  int rand_v = random(val); 
  int last = 0;
  buttonState = digitalRead(buttonPin);


  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,16);
  
  if (buttonState == HIGH) {
    display.println(val);
    display.display();
    display.clearDisplay();
  }
  else {
    last = rand_v;
    display.println(last);
    display.display();
    display.clearDisplay();
    delay(1000);
  }
  
}
