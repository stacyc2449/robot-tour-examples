const int out = 4;
const int digiRead = 6;
int voltage = 0;
int curVal;
int preVal;
bool repeat = false;
int encoderCount = 0;
long time;
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
  pinMode(digiRead, INPUT);
  analogWrite(out, voltage);
  curVal = digitalRead(digiRead);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  preVal = curVal;
  curVal = digitalRead(digiRead);
  repeat = digitalRead(digiRead) == preVal;
  if(!repeat){
    encoderCount++;
  }
  if(time >= 60000){
    Serial.println(encoderCount);
  }

}
