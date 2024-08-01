const int lightPin = 2;
int previousValue;
int currentValue;
int voltage = 200; //voltage to set motor speed
int encoderCount = 0;
bool repeat;
void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  currentValue = digitalRead(lightPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  previousValue = currentValue;
  currentValue = digitalRead(lightPin);
  repeat = previousValue == currentValue;
  if(!repeat){
    encoderCount++;
  }
  Serial.println(encoderCount);
}
