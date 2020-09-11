/* Code shared in creative common by MieRobot.com, This is not a production grade code and can not be used for industrial application*/
/*Obstacle avoidance arduino robot by MieRobot.com is licensed under a Creative Commons Attribution 4.0 International License.
Based on a work at https://www.youtube.com/channel/UCIpjehUq_j7OMnTl8MvSJrw. */

#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 
#include <SoftwareSerial.h>
// Declaration for LED only//
#include <FastLED.h>
// Datasheet for the LED is at https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf 
// How many leds in your strip? If your total current draw is > than 900mA then use a 330 ohm resitor and 100uF between 5V and ground
// Power Arduino by DC Barrel Jack and not via usb as with USB you will get around 400mA
#define NUM_LEDS 8 // Change this value if you have differnt number of LED

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 2
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

// End LED declarations

#define TRIG_PIN A0 
#define ECHO_PIN A1
#define MAX_DISTANCE 100 
#define MAX_SPEED 150 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20
 
 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
 // Adafruit motor driver shield version 2 only
AF_DCMotor motor1(1, MOTOR12_64KHZ); 
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR34_64KHZ);
AF_DCMotor motor4(4, MOTOR34_64KHZ);
Servo myservo;   
 
boolean goesForward=false;
int distance = 100;
int speedSet = 0;
 
void setup() {
 
  myservo.attach(10);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  // LED Setup starts

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // LED Setup ends
}
 
void loop() {
 int distanceR = 0;
 int distanceL = 0;
 delay(40);
 // led code
   leds[0] = CRGB::Red;
   leds[1] = CRGB::Red;
   leds[2] = CRGB::Red;
   leds[3] = CRGB::Green;
   leds[4] = CRGB::Green;
   leds[5] = CRGB::Blue;
   leds[6] = CRGB::Blue;
   leds[7] = CRGB::Blue;
  FastLED.show();
  delay(10);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  FastLED.show();
  delay(10);
  // led code end, Do not increase the delay as it will impact the obstacle mode in sharp turnes or blind spots
 
 if(distance<=25)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(200);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);
 
  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  } 
 
  else
 
  {
    turnLeft();
    moveStop();
  }
 } 
 
 else
 {
  moveForward();
 }
 distance = readPing();
}
 
int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}
 
int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}
 
int readPing() { 
  delay(100);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}
 
void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
 
void moveForward() {
 
 if(!goesForward)
  {
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);

   }
  }
}
 
void moveBackward() {
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}  
 
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void turnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
