/*
Arduino Robot Car with Ultrasonic Sensor HC-SR04 and Motion Sensor HC-SR501.
Author: Marc van Gorp
Last changed: 3-12-2020
*/

// define pin numbers
const int trigPin = 3;
const int echoPin = 2;
// define variables
long duration;
int distance;

const int ledPin = 13; // LED
const int pirPin = 4;  // PIR Out pin
int pirStat = 0;       // PIR status

const int motorsLeftPin = 5;  // Motors left
const int motorsRightPin = 6; // Motor right

void setup()
{
    Serial.begin(9600);              // Starts the serial communication
    pinMode(trigPin, OUTPUT);        // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);         // Sets the echoPin as an Input
    pinMode(ledPin, OUTPUT);         // Sets the ledPin as Output
    pinMode(pirPin, INPUT);          // Sets the pirPin as Input
    pinMode(motorsLeftPin, OUTPUT);  // Sets the motorsLeftPin as Output
    pinMode(motorsRightPin, OUTPUT); // Sets the motorsRightPin as Output
}
void loop()
{
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    pirStat = digitalRead(pirPin);
    if (pirStat == HIGH)
    {                               // if motion detected
        digitalWrite(ledPin, HIGH); // turn LED ON
    }
    else
    {
        digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
    }

    if (pirStat == HIGH & distance > 20) // if motion is detected and distance is bigger than 20 cm
    {
        digitalWrite(motorsLeftPin, HIGH);  // turn on left motors
        digitalWrite(motorsRightPin, HIGH); // turn on right motors
    }
    else
    {
        digitalWrite(motorsLeftPin, LOW);
        digitalWrite(motorsRightPin, LOW);
    }
}
