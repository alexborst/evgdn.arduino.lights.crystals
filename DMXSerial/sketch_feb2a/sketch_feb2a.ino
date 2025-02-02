#include <DMXSerial.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX on digital pins 10 and 11

void setup() {
    mySerial.begin(9600); // Use SoftwareSerial for debugging
    DMXSerial.init(DMXReceiver); // Initialize DMX receiver mode
    mySerial.println("DMX Receiver Ready");
}

void loop() {
    static uint32_t lastPrintTime = 0;
    uint32_t currentTime = millis();

    if (currentTime - lastPrintTime >= 1000) {
        mySerial.print("DMX Data: ");
        
        for (int i = 1; i <= 10; i++) {
            mySerial.print(DMXSerial.read(i));
            mySerial.print(" ");
        }

        mySerial.println();
        lastPrintTime = currentTime;
    }
}
