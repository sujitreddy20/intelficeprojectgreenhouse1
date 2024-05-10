#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2      // Pin connected to DHT11 sensor
#define DHTTYPE DHT11 // DHT sensor type
#define GAS_SENSOR_ANALOG_PIN A0 // Analog pin connected to gas sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 6); // Initialize LCD pins

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2); // Initialize LCD: 16 columns, 2 rows
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature (in Celsius)
  float humidity = dht.readHumidity();       // Read humidity

  // Read gas sensor value (replace with your specific gas sensor code)
  int gasValue = analogRead(GAS_SENSOR_ANALOG_PIN);
  
  // Print temperature and humidity on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Print gas sensor value on serial monitor
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);
  
  delay(2000); // Delay between readings
}
