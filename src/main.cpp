#include <LedController.hpp>

SimpleLedController ledController;

void setup(void) {
    ledController.initController();
//  ledController.setColorAll();
}

void loop() {
    //ledController.flashLight();
    ledController.rainbowDown();
}
