int measurePin = A5;
int ledPower = 12;
int relayPin = 11;  // Assuming relay control pin is connected to pin 11

unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  digitalWrite(ledPower, LOW);
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024);
  dustDensity = 0.17 * calcVoltage - 0.1;

  if (dustDensity < 0) {
    dustDensity = 0.00;
  }

  Serial.println("Raw Signal Value (0-1023):");
  Serial.println(voMeasured);

  Serial.println("Voltage:");
  Serial.println(calcVoltage);

  Serial.println("Dust Density:");
  Serial.println(dustDensity);

  // Check if dust density is above a certain threshold
  if (dustDensity > 0.5) {  // Adjust threshold value as needed
    // Turn on the relay to activate the pump
    digitalWrite(relayPin, HIGH);
    Serial.println("Pump activated!");  // Print a message indicating pump activation
  } else {
    // Turn off the relay
    digitalWrite(relayPin, LOW);
    Serial.println("Pump deactivated.");  // Print a message indicating pump deactivation
  }

  delay(1000);
}
