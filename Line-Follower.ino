// Line Follower Robot Code using 2 IR Sensors and L298N Motor Driver

// Motor pins
const int ENA = 9;    // PWM pin for left motor
const int IN1 = 8;
const int IN2 = 7;

const int ENB = 10;   // PWM pin for right motor
const int IN3 = 6;
const int IN4 = 5;

// IR sensor pins
const int leftSensor = 2;
const int rightSensor = 3;

void setup() {
  // Motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.println(rightValue);

  // Logic
  if (leftValue == 0 && rightValue == 0) {
    // Both sensors on white - stop
    stopMotors();
  } else if (leftValue == 1 && rightValue == 0) {
    // Turn left
    turnLeft();
  } else if (leftValue == 0 && rightValue == 1) {
    // Turn right
    turnRight();
  } else {
    // Go straight
    moveForward();
  }
}

// Movement functions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 180);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 180);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 180);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 180);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 180);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 180);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
