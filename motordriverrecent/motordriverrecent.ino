int enA = 9;
int enB = 10;
int in3 = 11;
int in4 = 12;
int in2 = 6;
int in1 = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  Serial.println("finished");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1500);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(1500);

}
