# Minecraft connected pickaxe

This is a project to use be able with a real pickaxe to mine in minecraft.
It is composed of an end device that will send request to a serveur whenever a bump is detected.

## Part list

* ESP32 S2 mini
* endstop switch
* 3.7V battery
* A computer to run the game and the server

## Code

### Server

To run the server you need to have python and pip installed _https://pip.pypa.io/en/stable/installation/_

`pip install flask`
`pip install pyautogui`
`python3 serveur.py`

The serveur code will simulate a left-click for 1 second whenever there is a get request that is made at http://<localip>:5000/click
You can find your local by looking at your IPV4 with `ipconfig` after opening a windows cmd or any other terminal

### ESP32

In the code for the ESP32 S2, you need to change the values for the SSID, the Password and the localip address,
Then you need to flash the code, I used platformIo but you can use whatever you want as long as you have these library included:
```
WIFI.h
HTTPClient.h
```
#### Upload code

Make S2 boards into Device Firmware Upgrade (DFU) mode.
Hold on Button 0
Press Button Reset
Release Button 0 When you hear the prompt tone on usb reconnection

For more info about the ESP32 S2: https://www.wemos.cc/en/latest/s2/s2_mini.html

Then connect the 3 wires of your endstop switch:
One on the ground for a reference of 0 when the switch is not pressed (or else you will have inconsistent values),
One on the 3.3V for when the switch is pressed
One on the A1 pin 1 for the input signal.

For the battery i recommend to have an easy system to plug -and not to directly solder the ground to the ground and the red wire to the Vbus- for easy charging.
