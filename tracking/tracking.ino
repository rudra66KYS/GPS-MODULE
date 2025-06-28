#include <SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;
SoftwareSerial ss(4, 3);  // RX, TX (TX is unused here, so pin 3 is not connected)

void setup() {
  Serial.begin(9600);    // Monitor GPS data via Serial Monitor
  ss.begin(9600);        // GPS baud rate, typically 9600
}

void loop() {
  while (ss.available() > 0) {
    gps.encode(ss.read());

    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
    }
  }
}
