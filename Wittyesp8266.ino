// The Witty Cloud Internet Of Things device 
// This example maps the basic pinout functions of the device. 
// 1. button_pin = digital pin 4
// ABOUT: This is A action push button on the board. One total included. 
// 2. esp8266 LED = digital pin 2
// 3. LDR_PIN = analog pin 0
// ABOUT: A photoresistor is a passive component that decreases 
// resistance with respect to receiving luminosity (light) on the 
// component's sensitive surface.
// 4. Red/Blue/Green all in one LED. 
// ABOUT: digital pins 3 total; Green is pin 12,
// Blue is pin 13 and Red is pin 15. Values and range are 0 to 100 max.
//
// Other Information about the arduino map function:
// the map() function uses integer math. So fractions might get suppressed 
// due to this. For example, fractions like 3/2, 4/3, 5/4 will all be returned 
// as 1 from the map() function, despite their different actual values. 
// So if your project requires precise calculations (e.g. voltage accurate to 3 decimal places), 
// please consider avoiding map() and implementing the calculations manually in your code yourself.
//
// Syntax of function map() : 
// map(value, fromLow, fromHigh, toLow, toHigh) 
// 
// The Maximum range is 1023 lumens total. The low range is a set point factor.   
//

#include <ESP8266WiFi.h>
const int LDR_PIN = A0; 
const int Green = 12;
const int Blue = 13;
const int Red = 15;
const int on_board_led = 2;
const int button_pin = 4; 

void setup() {
pinMode(button_pin, INPUT_PULLUP);
pinMode(on_board_led, OUTPUT); 
pinMode(Green, OUTPUT); 
pinMode(Blue, OUTPUT); 
pinMode(Red, OUTPUT); 
pinMode(LDR_PIN, INPUT);
RGB_LOW(); 
RGB_loop(); 
} 

// Setup functions 

void RGB_LOW() {
digitalWrite(Green, 0);
digitalWrite(Blue, 0); 
digitalWrite(Red, 0); 
}

void RGB_loop() { 
digitalWrite(on_board_led, LOW);
for (int i = 0; i <= 10; i++) {
digitalWrite(Green, 1);
delay(200); 
digitalWrite(Green, 0);
digitalWrite(Blue, 1); 
delay(200); 
digitalWrite(Blue, 0); 
digitalWrite(Red, 1);  
delay(200); 
digitalWrite(Red, 0);   
 }
 digitalWrite(on_board_led, HIGH);
}


void loop() {
  int btn_Status = HIGH;   
  btn_Status = digitalRead (button_pin);  // Check status of button
  if (btn_Status == LOW) {
RGB_LOW();         
runall(); 
}
int light_Intensity;
light_Intensity = analogRead(LDR_PIN);    
analogWrite(Blue, map(light_Intensity, 0,1023, 1023, 0));
analogWrite(Red, map(light_Intensity, 0,1023, 1023, 0));
analogWrite(Green, map(light_Intensity, 0,1023, 1023, 0));
}
void runall() {
onoff_Green(); 
BGR_slow(); 
BR_slow(); 
RGB_loop(); 
}

void BGR_slow() {
int x = 1300; 
delay(x); 
digitalWrite(on_board_led, LOW);
digitalWrite(Blue, 1); 
delay(x);
digitalWrite(on_board_led, HIGH); 
digitalWrite(Blue, 0); 
digitalWrite(Red, 1); 
delay(x); 
digitalWrite(Red, 0); 
digitalWrite(on_board_led, LOW);
digitalWrite(Blue, 1); 
delay(x); 
digitalWrite(on_board_led, HIGH);
digitalWrite(Blue, 0); 
digitalWrite(Green, 1);
delay(x); 
digitalWrite(Green, 0); 
}

void BR_slow() {
int x = 1300; 
delay(x); 
digitalWrite(Blue, 1); 
delay(x); 
digitalWrite(Blue, 0); 
digitalWrite(Red, 1); 
delay(x); 
digitalWrite(Red, 0); 
digitalWrite(Blue, 1); 
delay(x); 
digitalWrite(Blue, 0); 
}

void onoff_Green() {
int x = 1300; 
digitalWrite(Green, 1);
delay(x); 
digitalWrite(Green, 0); 
delay(x); 
}
