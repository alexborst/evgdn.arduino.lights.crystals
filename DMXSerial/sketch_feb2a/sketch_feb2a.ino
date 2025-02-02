#include <DMXSerial.h>

void setup() {
    Serial.begin(9600); // Start the Serial Monitor
    DMXSerial.init(DMXReceiver); // Initialize DMX in Receiver mode
    Serial.println("DMX Receiver Ready");
}

void loop() {
    static uint32_t lastPrintTime = 0;
    uint32_t currentTime = millis();

    // Print values every second to avoid spamming the Serial Monitor
    if (currentTime - lastPrintTime >= 1000) {
        Serial.print("DMX Data: ");
        
        // Read and display the first 10 DMX channels (1-10)
        for (int i = 1; i <= 10; i++) {
            Serial.print(DMXSerial.read(i));
            Serial.print(" ");
        }

        Serial.println(); // New line for readability
        lastPrintTime = currentTime;
    }
}
