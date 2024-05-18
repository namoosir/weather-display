#include <WiFi.h>
const char* ssid = "meem";      // Replace with your network SSID (name)
const char* password = "6478539650";  // Replace with your network password

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // Start the serial communication
  delay(10);

  connectToWifi();
}

void loop() {
  // put your main code here, to run repeatedly:
}
