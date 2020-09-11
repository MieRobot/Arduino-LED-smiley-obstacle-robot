# Arduino-LED-smiley-obstacle-robot
This is the code of a arduino obstacle robot with the WS2812B LED strips

![Happy obstacle avoid led robot robot Image 1 ](https://github.com/MieRobot/Arduino-LED-smiley-obstacle-robot/blob/master/obstacle%20happy%20robot%20with%20led.jpg)

### Summary:
This robot is a simple obstacle avoidance robot which uses an ultrasonic sensor and echo to detect an obstacle and change the path. There is additional 8 LED's in three different colors which can be changed from the code as well. In this code, it has a combination of 3 red, 2 green and 2 blue led. 

The motor driver is the adafruit driver version 2. The code is configured for 4 wheels but if you are using 2 wheeled robot then use channel 1 and 3. Pin 2 is the data pin for the LED and the ultrasonic sensor is at A0 and A1. 

### Things to note:

## Solder well 

Please solder well the DC motor and the 3 Pin LED Strip. It is advised that you solder header pins than wires for the LED WS2812B. See pictures of the soldering for an idea.

![Motors soldered Image 2 ](https://github.com/MieRobot/Arduino-LED-smiley-obstacle-robot/blob/master/motor%20soldered.jpg)

LED is soldered as below. If you are doing chains of LED then use both the ground. I have used one ground as I had only 8 LED's.

![LED soldered Image 3 ](https://github.com/MieRobot/Arduino-LED-smiley-obstacle-robot/blob/master/led%20soldered.jpg)

## Power Source

I have used a USB 2S 800 mAh battery via the barrel jack. If you power by the usb you will draw less current and your motors will move slower and also the LED may not be bright.

## 3D print the servo neck - File name model3.stl

You may 3D print the servo neck with the files in this repo. Below is the image in 3D designer.

![Servo neck in 3D Image 4 ](https://github.com/MieRobot/Arduino-LED-smiley-obstacle-robot/blob/master/paint3d%20servo%20holder.jpeg)

