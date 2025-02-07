#include <DMXSerial.h>

void setup() {
    Serial.begin(9600);  // Start serial communication for monitoring
    DMXSerial.init(DMXReceiver);  // Initialize DMX in receiver mode
    Serial.println("DMX Receiver Ready");
}

void loop() {
    // Check if new data has been received
    if (DMXSerial.receive()) {
        Serial.println("DMX Data Received:");
        
        // Read the first 10 channels for monitoring
        for (int i = 1; i <= 10; i++) {
            Serial.print("Channel ");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(DMXSerial.read(i));  // Read value of channel i
        }
        
        Serial.println("-------------------------");
        delay(1000);  // Slow down output for readability
    }
}
