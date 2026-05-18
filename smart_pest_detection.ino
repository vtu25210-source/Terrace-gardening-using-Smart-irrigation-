#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4

long duration;
int distance;
int alertDistance = 20; // Distance in centimeter

void setup() 
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // 10μs pulse is sent to trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the duration of the echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in centimeter
  distance = duration * 0.034 / 2;
  
  // Serial monitor output
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // If an object is too close, buzzer is activated
  if (distance <= alertDistance) 
  {
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer turned on
  } 
  else 
  {
    digitalWrite(BUZZER_PIN, LOW); // Buzzer turned off
  }
  
  delay(500);
}