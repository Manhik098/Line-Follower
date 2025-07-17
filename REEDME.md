# 🤖 Line Follower Robot using Arduino

A simple and effective Line Follower Robot project using an Arduino Uno, two IR sensors, and a dual DC motor setup via L298N Motor Driver.

---

## 🚀 Features

- Follows a black line on white surface
- Detects left and right turns
- Stops when line is lost
- Easy to customize motor speed and logic

---

## 🛠️ Hardware Required

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| IR Sensors (TCRT5000)  | 2        |
| L298N Motor Driver     | 1        |
| DC Motors              | 2        |
| Robot Chassis + Wheels| 1 set    |
| Jumper Wires           | -        |
| Power Supply (6–12V)   | 1        |

---

## 🧠 Circuit Connections

### IR Sensors:
- `Left IR Sensor OUT` → Arduino `pin 2`
- `Right IR Sensor OUT` → Arduino `pin 3`

### Motors via L298N:
- `IN1` → pin 8
- `IN2` → pin 7
- `ENA` (Left PWM) → pin 9
- `IN3` → pin 6
- `IN4` → pin 5
- `ENB` (Right PWM) → pin 10
- Power L298N with 6–12V

---

## 🔌 How It Works

| Sensor State | Action        |
|--------------|---------------|
| Both 0       | Stop          |
| Left 1       | Turn Left     |
| Right 1      | Turn Right    |
| Both 1       | Move Forward  |

- `1` = IR detects black line
- `0` = IR sees white surface

--

