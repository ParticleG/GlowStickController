#include <LedController.hpp>

SimpleLedController ledController;

void setup(void) {
    ledController.initController();
}

void loop() {
    // double input = analogRead(15) / 1023.0;
    // ledController.constant(350.0 / 360.0, 1.0, input);
    // ledController.constantBar(0, 255, 0, 0);
    // ledController.constantBar(1, 0, 255, 0);
    // ledController.constantBar(2, 0, 0, 255);
    // Serial.println(analogRead(15));
    // ledController.breathe(0.0, 0.8, 0.3, 100);
    ledController.rainbowUp(50);
}
