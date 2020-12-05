const int pinSensorProxEcho = 2;
const int pinSensorProxTrig = 3;
const int pinSensorMotion = 4;

void setup()
{
    Serial.begin(9600);
    pinMode(pinSensorMotion, INPUT);
    pinMode(pinSensorProxEcho, INPUT);
    pinMode(pinSensorProxTrig, INPUT);
}

void loop()
{
}