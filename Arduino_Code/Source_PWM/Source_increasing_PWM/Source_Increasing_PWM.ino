const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

void setup()
{
    Serial.begin(115200);

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENA,255);
    delay(2000);
}

void loop()
{
    // Tăng tốc
    for(int pwm = 0; pwm <= 255; pwm += 5)
    {
        analogWrite(ENA,pwm);

        Serial.println(pwm);   // Gửi đúng 1 số

        delay(50);
    }

    delay(3000);

    // Giảm tốc
    for(int pwm = 255; pwm >= 0; pwm -= 5)
    {
        analogWrite(ENA,pwm);

        Serial.println(pwm);

        delay(50);
    }

    delay(1000);
}