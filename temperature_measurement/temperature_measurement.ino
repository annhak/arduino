// Temperature sensing with LED indications for too high and low temperatures

const int sensorPin = A0;

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  float temperature = ((sensorVal / 1024.0 * 5.0) - 0.5) * 100.0;
  Serial.print("Measured temperature: ");
//  Serial.println(sensorVal);
  Serial.println(temperature);
  
  // Shut all LEDs
  for (int i = 3; i<6; i++) {
    digitalWrite(i, LOW);
  }
  
  if (temperature < 21) {
    digitalWrite(4, HIGH); // blue
  } 
  else if (temperature > 27) {
    digitalWrite(5, HIGH); // red
  }
  else {
    digitalWrite(3, HIGH); // green
  }
  delay(1000);
}
