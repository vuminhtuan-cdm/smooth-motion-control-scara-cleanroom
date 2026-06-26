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
    
    
    // Tăng tốc chạy 50 bước, biến x chạy từ -6.0 đến +6.0
   
    for(int i = 0; i <= 50; i++)
    {
        // Chuyển đổi i (0 -> 50) thành x (-6.0 -> +6.0)
        float x = -6.0 + (i / 50.0) * 12.0;
        
        //  Sigmoid 
        float sigmoid = 1.0 / (1.0 + exp(-x));
        
        // đổi giá trị sigmoid sang PWM
        int pwm = int(sigmoid * 255.0);
        
        analogWrite(ENA, pwm);
        Serial.println(pwm); 
        delay(50);
    }

    
    // GIỮ TỐC ĐỘ TỐI ĐA (Đồ thị nằm ngang ở đỉnh 255)
    // Giữ trong 3 giây (60 lần * 50ms)
    
    for(int i = 0; i < 60; i++)
    {
        analogWrite(ENA, 255);
        Serial.println(255);   
        delay(50);             
    }

    
    // GIẢM TỐC KIỂU SIGMOID (S-Curve đảo ngược)
    // Chạy 50 bước, biến x chạy từ +6.0 về -6.0
    
    for(int i = 0; i <= 50; i++)
    {
        // Đi ngược lại: x chạy từ +6.0 về -6.0
        float x = 6.0 - (i / 50.0) * 12.0;
        
        float sigmoid = 1.0 / (1.0 + exp(-x));
        int pwm = int(sigmoid * 255.0);
        
        analogWrite(ENA, pwm);
        Serial.println(pwm); 
        delay(50);
    }

    
    // NGHỈ Ở ĐÁY (Đồ thị nằm ngang ở đáy 0)
    // Nghỉ 1 giây (20 lần * 50ms)
   
    for(int i = 0; i < 20; i++)
    {
        analogWrite(ENA, 0);   
        Serial.println(0);     
        delay(50);
    }
}