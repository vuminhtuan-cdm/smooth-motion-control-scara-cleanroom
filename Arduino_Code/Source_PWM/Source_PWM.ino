const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, 255); // đá khởi động
  delay(2000);
}

void loop() {

  analogWrite(ENA, 80);   // ~31%
delay(5000);

analogWrite(ENA, 130);  // ~51%
delay(5000);

analogWrite(ENA, 190);  // ~75%
delay(5000);

analogWrite(ENA, 255);  // 100%
delay(5000);
}