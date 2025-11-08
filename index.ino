/*
  --- Group 6: Practical Assignment ---
  Cloud-Connected Weather Station
  Reads Temperature and Light, then prints to 
  the Serial Monitor (our simulated cloud dashboard).
*/

// Define our sensor pins
#define TMPPIN A0      // TMP36 Vout pin is on A0
#define LDRPIN A1      // LDR (photoresistor) is on A1

void setup() {
  // Start the Serial Monitor
  Serial.begin(9600);
}

void loop() {
  delay(500);

  // --- Read Sensors ---

  int lightReading = analogRead(LDRPIN); // (value from 0-1023)
  float lightLevel = ((lightReading - 54) / 920) * 100; // (value from 0-100) 
  
  int tempReading = analogRead(TMPPIN); // (value from 0-1023)
  float voltage = tempReading * (5.0 / 1023.0); // Convert to voltage (0-5V)
  float temperatureC = (voltage - 0.5) * 100.0; // (Sensor spec: (Voltage - 0.5V) * 100)


  // --- Sending to "Cloud" (Serial Monitor) ---
  
  // We've removed humidity from our message as
  // we couldn't find the DHT11 (temp+humid) sensor
  
  Serial.print("{\"temp\": " + String(temperatureC) + " `C, ");
  Serial.print("\"light\": " + String(lightLevel) + "%}\n");
}