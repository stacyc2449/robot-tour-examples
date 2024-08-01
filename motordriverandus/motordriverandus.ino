const int pwmLeft = 5;
const int pwmRight = 6;
const int forwardLeft = 2; //left = motor A
const int backLeft = 3;
const int forwardRight = 4; //right = motor B
const int backRight = 7;
const int trigPin = 8;
const int echoPin = 9;
//ultrasonic sensor
long ultraAvg[4];
long average;
int duration;
//drive
int normalSpeed = 300;
int slowSpeed = 100;

void setup() {
  //put your setup code here, to run once:
  pinMode(pwmLeft, OUTPUT);
  pinMode(pwmRight, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  pinMode(backLeft, OUTPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(backRight, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  for(int i = 0; i < 4; i++){
    readSensor();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensor();
  average = avgSensor();
  Serial.println(average);
  if(average > 20){
    analogWrite(pwmLeft, normalSpeed);
    analogWrite(pwmRight, normalSpeed);

    digitalWrite(forwardLeft, HIGH);
    digitalWrite(backLeft, LOW);
    digitalWrite(forwardRight, HIGH);
    digitalWrite(backRight, LOW);
  }else{
    analogWrite(pwmLeft, normalSpeed);
    analogWrite(pwmRight, normalSpeed);

    digitalWrite(forwardLeft, HIGH);
    digitalWrite(backLeft, LOW);
    digitalWrite(forwardRight, LOW);
    digitalWrite(backRight, HIGH);
  }

}

void readSensor(){
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  for(int i = 0; i < 3; i++){
    ultraAvg[i] = ultraAvg[i + 1];
  }
  ultraAvg[3] = duration * 0.034/2;
}

long avgSensor(){
  long sum = 0;
  for(int i = 0; i < 4; i++){
    sum += ultraAvg[i];
  }
  return sum/4.0;
}