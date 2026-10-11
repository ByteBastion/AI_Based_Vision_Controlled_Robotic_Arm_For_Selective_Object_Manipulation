/*
 * AI-Based Vision Controlled Robotic Arm - Arduino Motor Controller
 * 
 * Hardware: Arduino Mega / Uno with L298N Dual H-Bridge Motor Drivers
 * Actuation: 5-DOF DC Gearmotors with directional pin pairs and PWM enable pins
 * Baud Rate: 9600 bps
 *
 * Command Protocol:
 *  - Base:      'B' (Left)     / 'N' (Right)
 *  - Shoulder:  'S' (Up)       / 'X' (Down)
 *  - Elbow:     'E' (Forward)  / 'Z' (Backward)
 *  - Wrist:     'W' (Forward)  / 'Y' (Backward)
 *  - Gripper:   'G' (Close)    / 'H' (Open)
 */

// Pin Definitions for L298N Motor Drivers
// Gripper Motor
const int GRIPPER_IN1 = 22;
const int GRIPPER_IN2 = 23;
const int GRIPPER_ENA = 5;

// Wrist Motor
const int WRIST_IN1   = 24;
const int WRIST_IN2   = 25;
const int WRIST_ENB   = 6;

// Shoulder Motor
const int SHOULDER_IN1 = 26;
const int SHOULDER_IN2 = 27;
const int SHOULDER_ENA = 7;

// Elbow Motor
const int ELBOW_IN1   = 28;
const int ELBOW_IN2   = 29;
const int ELBOW_ENB   = 8;

// Base Motor
const int BASE_IN1    = 30;
const int BASE_IN2    = 31;
const int BASE_ENA    = 9;

// Movement Timings (milliseconds per command burst)
const int BASE_DELAY     = 100;
const int SHOULDER_DELAY = 120;
const int ELBOW_DELAY    = 110;
const int WRIST_DELAY    = 90;
const int GRIPPER_DELAY  = 200;

// Motor speed (PWM duty cycle 0-255)
const int MOTOR_PWM_SPEED = 180;

void stopMotor(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void moveMotor(int in1, int in2, int enablePin, int pulseDelayMs, bool forward) {
  analogWrite(enablePin, MOTOR_PWM_SPEED);

  if (forward) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  delay(pulseDelayMs);
  stopMotor(in1, in2);
}

void setup() {
  Serial.begin(9600);

  // Initialize all motor control pins as outputs
  pinMode(GRIPPER_IN1, OUTPUT);
  pinMode(GRIPPER_IN2, OUTPUT);
  pinMode(GRIPPER_ENA, OUTPUT);

  pinMode(WRIST_IN1, OUTPUT);
  pinMode(WRIST_IN2, OUTPUT);
  pinMode(WRIST_ENB, OUTPUT);

  pinMode(SHOULDER_IN1, OUTPUT);
  pinMode(SHOULDER_IN2, OUTPUT);
  pinMode(SHOULDER_ENA, OUTPUT);

  pinMode(ELBOW_IN1, OUTPUT);
  pinMode(ELBOW_IN2, OUTPUT);
  pinMode(ELBOW_ENB, OUTPUT);

  pinMode(BASE_IN1, OUTPUT);
  pinMode(BASE_IN2, OUTPUT);
  pinMode(BASE_ENA, OUTPUT);

  // Ensure all motors start stopped
  stopMotor(GRIPPER_IN1, GRIPPER_IN2);
  stopMotor(WRIST_IN1, WRIST_IN2);
  stopMotor(SHOULDER_IN1, SHOULDER_IN2);
  stopMotor(ELBOW_IN1, ELBOW_IN2);
  stopMotor(BASE_IN1, BASE_IN2);

  Serial.println(F("[READY] Robotic Arm Controller initialized."));
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      // Base Rotation
      case 'B':
        moveMotor(BASE_IN1, BASE_IN2, BASE_ENA, BASE_DELAY, true);
        break;
      case 'N':
        moveMotor(BASE_IN1, BASE_IN2, BASE_ENA, BASE_DELAY, false);
        break;

      // Shoulder Joint
      case 'S':
        moveMotor(SHOULDER_IN1, SHOULDER_IN2, SHOULDER_ENA, SHOULDER_DELAY, true);
        break;
      case 'X':
        moveMotor(SHOULDER_IN1, SHOULDER_IN2, SHOULDER_ENA, SHOULDER_DELAY, false);
        break;

      // Elbow Joint
      case 'E':
        moveMotor(ELBOW_IN1, ELBOW_IN2, ELBOW_ENB, ELBOW_DELAY, true);
        break;
      case 'Z':
        moveMotor(ELBOW_IN1, ELBOW_IN2, ELBOW_ENB, ELBOW_DELAY, false);
        break;

      // Wrist Joint
      case 'W':
        moveMotor(WRIST_IN1, WRIST_IN2, WRIST_ENB, WRIST_DELAY, true);
        break;
      case 'Y':
        moveMotor(WRIST_IN1, WRIST_IN2, WRIST_ENB, WRIST_DELAY, false);
        break;

      // Gripper Claw
      case 'G':
        moveMotor(GRIPPER_IN1, GRIPPER_IN2, GRIPPER_ENA, GRIPPER_DELAY, true);
        break;
      case 'H':
        moveMotor(GRIPPER_IN1, GRIPPER_IN2, GRIPPER_ENA, GRIPPER_DELAY, false);
        break;

      default:
        // Ignore whitespace, newlines, and unrecognized characters
        break;
    }
  }
}