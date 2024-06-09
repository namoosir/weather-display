#include "weatherDisplay.h"

void connectToWifi() {
  // Connect to Wi-Fi
  Serial.print("\nConnecting to ");
  Serial.print(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void fetchWeatherData() {
  if (WiFi.status() == WL_CONNECTED) { // Check if the device is connected to Wi-Fi
    HTTPClient http;
    http.begin(WEATHER_URL); // Specify the URL
    int httpResponseCode = http.GET(); // Make the request

    if (httpResponseCode > 0) { // Check for a successful response
      String payload = http.getString();
      Serial.println("Weather data:");
      Serial.println(payload); // Print the response payload
    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Free resources
  } else {
    Serial.println("Error in WiFi connection");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // Start the serial communication
  delay(10);

  connectToWifi();
  fetchWeatherData();
}

void loop() {
  // put your main code here, to run repeatedly:
}
