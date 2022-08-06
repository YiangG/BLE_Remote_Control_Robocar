# BLE_Remote_Control_Robocar

![overview](image/overview.JPG)

ESP32 Remote control car by BLE via Dabble

## Objective: 
Build a wireless controlled robocar toy, reusing the chassis from a class project remaining. 

## Materials:
1.	ESP32 Pico
2.	L298N Motor Driver
3.	A switch button
4.	9v battery
5.	2 Generic TT DC motor
6.	2 Wheels
7.	A Ball Caster

## Schematics:
![schematic](image/schematic.png)

## Code:
As you notice, there are two folder in this repo and they are corresponding to the two version of the code I wrote, which are very self explanatory ----- the joystick one uses the joystick feature in Dabble App, and the direction key version uses the direction keys. **I recommend you to use the direction key version** for better control experience. The joystick is a bit messy. 

## Demo: 
![bot](image/bottom.JPG)

I combined two battery cases to be able to use AA battery as 9V battery. The case is inherited from class project as well, and you dont have to use exact 9V in this project. Any voltage source from 7 to 12V is okay. 
![battery](image/battery.JPG)

![demo](image/demo.gif)
