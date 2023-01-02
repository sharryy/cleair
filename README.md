# Arduino Smoke Detector System

This project uses an Arduino microcontroller to build a smoke detector system that can detect the presence of smoke and trigger an alarm. Additionally, it can send data to thingspeak where we can visualize the change in data.


### Hardware Components

1. Arduino board (e.g. Arduino Uno)
2. Smoke sensor (e.g. MQ-2 smoke sensor)
3. Buzzer or speaker for the alarm

### Usage

1. Connect the hardware components according to circuit diagram
2. Upload the code to the Arduino board.
3. The smoke detector system is now operational. If the smoke sensor detects smoke, the alarm will be triggered.

### How to setup Code?

Replace the `CHANNEL_NUMBER` and `API_KEY` variables in the code by your actual keys from [Thingspeak](https://thingspeak.com/). Also replace network ssid and password with actual values.

### TinkerCad Implementation

The circuit deigned in TinkerCad is different from the hardware circuit. Esp32 is used in hardware but it is not available in Tinkercad, so circuit on TinkerCad is implemented using Arduino UNO. Moreover, we have used an LCD to display the data being sensed by the sensor. There is one limitation of Tinkercad that we can't use WIFI Module there because of security reasons. Hence we used an LCD to display data.

### Circuit Diagram

![Circuit Diagram](https://github.com/sharryy/cleair/blob/main/assets/circuit-diagram.jpeg)


### Customization

You can customize the threshold for triggering the alarm by modifying the value in the if statement in the loop function. For example, to increase the sensitivity of the smoke detector, you can lower the threshold value.

```
if (sensor_Aout > 1000) {
  // code to execute if sensor value is above threshold
} else {
  // code to execute if sensor value is below threshold
}

```

### Contribute

We welcome contributions to this project! If you have an idea for a new feature or have found a bug, please open an issue or submit a pull request.

