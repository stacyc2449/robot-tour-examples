#include <Arduino.h>
#include <math.h>
#include <PID_v1.h>

//pins
const uint8_t leftEncoderPin = 3;
const uint8_t rightEncoderPin = 13;

const uint8_t in1Pin = 7; //9
const uint8_t in2Pin = 6; //8
const uint8_t in3Pin = 11; //7
const uint8_t in4Pin = 12; //6
const uint8_t enAPin = 9; //11
const uint8_t enBPin = 10; //10

double current_Distance = 0;
double voltage;
double error;
double setpoint = 100;

int leftEncoderCount = 0;
int leftPreviousCount = 0;
int rightEncoderCount = 0;
int rightPreviousCount = 0;
int leftPreviousValue;
int leftCurrentValue;
int rightPreviousValue;
int rightCurrentValue;

int encoder_count = 0;

struct{
  double kP = 120;
  double kI = 20;
  double kD = 50;
} distancePID;

struct{
  double kP = 100;
  double kI = 20;
  double kD = 50;
} rotPID;

struct{
  int kS = 90;
  int kV = 0;
  int kA = 0;
} driveFF;

PID pidDisController(&current_Distance, &error, &setpoint, distancePID.kP, distancePID.kI, distancePID.kD, DIRECT);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("step 1 started");
  pinMode(leftEncoderPin, INPUT);
  pinMode(rightEncoderPin, INPUT);

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enAPin, OUTPUT);
  pinMode(enBPin, OUTPUT);

  pidDisController.SetOutputLimits(-180, 180);

  pidDisController.SetMode(AUTOMATIC);

  voltage = 140;
}

void loop() {
  // put your main code here, to run repeatedly:
  leftPreviousValue = leftCurrentValue;
  rightPreviousValue = rightCurrentValue;
  leftCurrentValue = digitalRead(leftEncoderPin);
  rightCurrentValue = digitalRead(rightEncoderPin);

  if(leftPreviousValue != leftCurrentValue){
      leftEncoderCount++;
  }
  if(rightPreviousValue != rightCurrentValue){
      rightEncoderCount++;
  }

  current_Distance = (leftEncoderCount + rightEncoderCount) / 2.0;

  pidDisController.Compute();

  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);

  analogWrite(enAPin, voltage );
  analogWrite(enBPin, voltage );

  Serial.println(voltage);

}
