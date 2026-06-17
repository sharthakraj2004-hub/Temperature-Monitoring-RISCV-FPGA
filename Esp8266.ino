#define BIT0 5
#define BIT1 4
#define BIT2 14
#define BIT3 12

void setup()
{
    pinMode(BIT0, OUTPUT);
    pinMode(BIT1, OUTPUT);
    pinMode(BIT2, OUTPUT);
    pinMode(BIT3, OUTPUT);

    Serial.begin(115200);

    Serial.println("ESP8266 ADC GPIO Sender Started");
}

void loop()
{
    int adc = analogRead(A0);

    // Scale 0-1023 to 0-15
    int adc4 = adc / 64;

    if(adc4 > 15)
        adc4 = 15;

    // Send 4-bit value
    digitalWrite(BIT0, (adc4 >> 0) & 1);
    digitalWrite(BIT1, (adc4 >> 1) & 1);
    digitalWrite(BIT2, (adc4 >> 2) & 1);
    digitalWrite(BIT3, (adc4 >> 3) & 1);

    Serial.print("ADC = ");
    Serial.print(adc);

    Serial.print("   ADC4 = ");
    Serial.println(adc4);

    delay(500);
}
