# Ultrasonic Distance Detection with LED Indicators

This project uses an **HC-SR04 ultrasonic sensor** to measure distance and trigger different sets of LEDs based on whether an object is closer than 15 cm or farther away. It's a simple yet practical demonstration of distance-based automation using Arduino.

---

## 📦 Features

- Measures distance using an ultrasonic sensor.
- Lights up different LEDs depending on the measured distance.
  - 🔴 If distance < 15 cm → LEDs on pins **1 & 2** turn ON.
  - 🟢 If distance ≥ 15 cm → LEDs on pins **3 & 4** turn ON.
- Real-time distance output via Serial Monitor.

---

## 🧰 Components Required

- Arduino Uno (or compatible board)
- HC-SR04 Ultrasonic Sensor
- 4x LEDs
- Breadboard + jumper wires
- USB cable

---

## 🔌 Wiring Diagram

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | 10          |
| ECHO        | 9           |

| LED         | Arduino Pin |
|-------------|-------------|
| LED1 (Low)  | 1           |
| LED2 (Low)  | 2           |
| LED3 (High) | 3           |
| LED4 (High) | 4           |

> 💡 **Note:** You may need to change pin 1 if it causes issues with Serial communication.
![Ultrasonic Distance Detection with LED  Wiring Diagram](fgfg)
---

## 🧠 How It Works

The code sends a 10µs pulse to the ultrasonic sensor to initiate a reading. Then it listens for the echo and calculates the time it takes for the pulse to return. Using this time, the distance is calculated in centimeters. Based on the result:

- If **distance < 15 cm**, two LEDs light up (LOW zone).
- If **distance ≥ 15 cm**, two other LEDs light up (HIGH zone).

---

## 🖥️ Code Overview

```cpp
#define ECHOPIN 9
#define TRIGPIN 10
int lowPins[] = {1, 2};
int highPins[] = {3, 4};

float distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  for (int i = 0; i < 2; i++) {
    pinMode(lowPins[i], OUTPUT);
    pinMode(highPins[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(TRIGPIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  distance = pulseIn(ECHOPIN, HIGH) / 58.0;
  Serial.print(distance); Serial.println(" cm");

  if (distance < 15) {
    for (int i = 0; i < 2; i++) {
      digitalWrite(lowPins[i], HIGH);
      digitalWrite(highPins[i], LOW);
    }
  } else {
    for (int i = 0; i < 2; i++) {
      digitalWrite(lowPins[i], LOW);
      digitalWrite(highPins[i], HIGH);
    }
  }

  delay(200);
}



```
## 🧠 How It Works

The ultrasonic sensor sends out a signal and measures the time it takes for the echo to return. If the distance is less than 15 cm, two LEDs light up. Otherwise, two different LEDs light up.

## 🖥️ Arduino Code

See `ultrasonic_distance_led.ino`

## 📜 License

This project is open-source and free to use under the MIT License.

## ✍️ Author

Developed by **Ahmed Mohamed Attia**  
- GitHub: [Ahm3d0x](https://github.com/Ahm3d0x)  
- LinkedIn: [ahmed-m-attia-757aa6292](https://linkedin.com/in/ahmed-m-attia-757aa6292)  
- Email: ahm3d.m.attia@gmail.com  

