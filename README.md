
# HomeControl
HomeControl is a Norwegian energy management and home automation provider.
More information about the system and preorders can be found here:
- [Wattle](https://wattle.com/)

### Why this library
HomeControl provides an open source Arduino library for integration with Your smart home. This library enables microcontrollers, with MQTT capability, to connect to the HomeControl system. This gives You, as a user, the ability to use HomeControl solution for home automation with Your DIY hardware. You can use gateway and app to have control and feedback over all Your devices. It runs on super-low cost hardware and can be used to integrate Your existing projects.

### MQTT
MQTT is a machine-to-machine (M2M)/"Internet of Things" open source connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport. It is useful for connections with remote locations where a small code footprint is required and/or network bandwidth is at a premium.

# Getting started:
The Arduino Software (IDE) allows you to write examples and upload them to your board. IDE can be downloaded [here](https://www.arduino.cc/en/Main/Software). If you have a reliable internet connection, you can use the [online IDE](https://create.arduino.cc/). It will allow you to save your sketches in the cloud, having them available from any device and backed up.

To download HomeControl open source Arduino library, click the DOWNLOAD button in the top right corner and uncompress the folder. Place the homecontrol library folder to your /libraries/folder. You may need to create the libraries subfolder if this is your first library. Restart the IDE.

Repeat the procedure with following Arduino libraries to use this class:
- [Loops](https://github.com/seky2205/NetworkLoops)
- [PubSubClient](https://github.com/knolleary/pubsubclient)

You can open one of the HomeControl example sketch: File > Examples > homecontrol-mqtt

Select the board You are using (Tools > Board) and correct serial port of the board (Tools > Port).
If You are using one of the verified ESP controllers, start IDE and open Preferences window. Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field. You can add multiple URLs, separating them with commas. Open Boards Manager from Tools > Board menu and install esp8266 platform (don't forget to select your ESP8266 board from Tools > Board menu after installation).
On Windows, port this should be something like COM2 (or some other number), on the Mac, this should be something like /dev/cu.usbserial-1B1.

Push the reset button on the board then click the Upload button in the IDE. Wait a few seconds. If successful, the message "Done uploading." will appear in the status bar.

# Examples:
HomeControl is providing You six examples composed of specific endpoints for each application:
- basic_OnOff - with this example, it is possible to control and have a feedback with any existing device which use a digital control signal (on/off).
- basic_Level - example Level allows you to manage and feedback any existing device which use analog control signal. This example also uses the functionality of the basic_OnOff example.
- basic_Color - allows you to turn ON or OFF, set color and brightness of RGB LED strip.
- basic_Temperature - periodically sends information about the current temperature and/or the relative humidity of the area, every 60 seconds or any other time period if so defined. DHT22 temperature sensor is used as an example.
- basic_TemperatureTarget_OnOff - the thermostat is a device for controlling and regulating indoor temperature. If the current measured room temperature is less than the set temperature in the application, the relay activation burns the heater and warms up the area. Room temperature is measured periodically, and as a result of the desired value, the relay is switched off.
- basic_Motion - when motion is detected, user will get notification from the application, e-mail and/or SMS depending on what is selected in the configuration of the device. In this example, PIR motion sensor treggers alarm if armed in the application, in the same way it is possible to connect any digital sensor. For example: rain sensor, gas, smoke, presence, magnetic sensor...

Your smart devices can be a combination of multiple endpoints from this library. On that way can be implemented devices for virtually every user need.

# List of library functions:

### Explanations:
* Reporting: device needs to send every X number of seconds update of state, or system will mark it as offline
* Control functions have direction Driver->Device and are used to set values
* Status functions have direction Device->Driver and are used as feedback to update values in driver. If not set differently, the default value will be used from driver.

### Explanation:
1. function
    * function identifier
    * default reporting time
    * value type
    * description

# List of functions:
1. control_power
    * cp
    * 0
    * bool
    * Receives on or off to control output

1. status_power
    * sp
    * 30
    * bool
    * Feedback to app if output/input is on or off

1. control_level
    * cl
    * 0
    * uint 0-10000
    * On device you will get number in this range when set in app

1. status_level
    * sl
    * 30
    * uint 0-10000
    * Device returns status of its analog output

1. status_temperature
    * st
    * 60
    * float
    * Reports back temperature in Degrees Celsius

1. status_temperature_target
    * stt
    * 60
    * float
    * Report back temperature target in Degrees Celsius

1. control_temperature_target
    * ctt
    * 0
    * float
    * Will receive temperature setpoint in Degress Celsius

1. control_color
    * cc
    * 0
    * uint 0-10000
    * On device you will get number in this range for each color (R,G,B) when set in app

1. status_color
    * sl
    * 30
    * uint 0-10000
    * Device returns the status of the current set color

1. status_motion
    * sm
    * 30
    * bool
    * Feedback to app if motion sensor is triggered

1. control_identify
    * ci
    * 0
    * bool
    * Will receive 1 if identify is triggered
