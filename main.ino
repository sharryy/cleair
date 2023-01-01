#include "WiFi.h"
#include "ThingSpeak.h"
int buzzer = 32;
int Sensor_input = 34;

const char* ssid = "<network-ssid-here>";             
const char* password = "<network-password>";  

WiFiClient client;
unsigned long lastTime = 0;
unsigned long myChannelNumber = 1992567;
const char* myWriteAPIKey = "VVMXFIA4TD1OB51E";

void setup() {
  Serial.begin(115200);
  Serial.print("Sensor Warming up!");
  Serial.print("\n");
  pinMode(buzzer, OUTPUT);
  ledcSetup(0, 1E5, 12);
  ledcAttachPin(buzzer, 0);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop() {
  if ((millis() - lastTime) > 3000) {

    // Connect or reconnect to WiFi
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Attempting to connect");
      while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
        delay(5000);
      }
      Serial.println("\nConnected.");
    }
    int sensor_Aout = analogRead(Sensor_input);
    Serial.print("Gas Sensor: ");
    Serial.print(sensor_Aout);
    Serial.print("\t");
    Serial.print("\t");
    int x = ThingSpeak.writeField(myChannelNumber, 1, sensor_Aout, myWriteAPIKey);
    if (sensor_Aout > 1000) {
      Serial.println("Gas");
      ledcWriteTone(buzzer, 800);
      uint8_t octave = 1;
      ledcWriteNote(0,NOTE_C,octave);      
    } else {
      Serial.println("No Gas");
      ledcWriteTone(buzzer, 0);
    }
    if (x == 200) {
      Serial.println("Channel update successful.");
    } else {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
