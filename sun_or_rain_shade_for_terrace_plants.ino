#include <Servo.h>
Servo myservo; // Create an object Servo

int lm35Sensor = A0; // LM35 temperature sensor connected to Analog pin 0
int rainSensor = 2; // Rain sensor connected to pin 2
int thresholdTemperature = 25; // Threshold temperature in Celsius
int thresholdRainValue = 500; // Threshold value for rain detection

void setup() 
{
  myservo.attach(9); // Servo connected to pin 9
  pinMode(rainSensor, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int temperature = readTemperature();
  int rainValue = digitalRead(rainSensor);

  if (temperature > thresholdTemperature && rainValue < thresholdRainValue) 
  {
    // If both conditions true, servo rotates to 180 degree
    myservo.write(180);
    delay(1000); 
    myservo.write(0); // Servo returns back to 0 degrees
  }
  else 
  {
    // If the conditions are not true
    myservo.write(0);
  }
}

int readTemperature() // Function to read the temperature
{
  int Value = analogRead(lm35Sensor);
  float voltage = (Value / 1024.0) * 5.0; // Convert value to voltage
  float temperatureCelsius = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius
  return int(temperatureCelsius);
}






