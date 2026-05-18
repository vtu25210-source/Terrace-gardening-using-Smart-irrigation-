#define MOISTURE_SENSOR A0
#define RELAY_PIN 2

int moisture = 500; // threshold moisture

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Water pump is in off state
  Serial.begin(9600);
}

void loop() 
{
  int moistureValue = analogRead(MOISTURE_SENSOR);

  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  if (moistureValue < moisture) 
  {
    Serial.println("Soil is dry. Turning on water pump and valve.");
    digitalWrite(RELAY_PIN, HIGH); // Water pump runs when relay is turned on
    delay(10000); // Pump runs for 10 seconds (adjustable)
    digitalWrite(RELAY_PIN, LOW); // Turn off the relay
    Serial.println("Watering completed.");
  }

  delay(60000); // Soil moisture is checked after 1 minute (adjustable)
}

