//
// Created by Particle_G on 2020/7/25.
//

#include "LedController.hpp"

void MinimalLedController::initController() {
    Serial.begin(SERIAL_NUMBER);
    ledBar_1.begin();
    ledBar_2.begin();
    ledBar_3.begin();
}

void MinimalLedController::setColorAll() {
    for (int address = 0; address < LED_COUNT; address++) {
        ledBar_1.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
        ledBar_2.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
        ledBar_3.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
    }
}

void MinimalLedController::setColorAll(const int &red, const int &green, const int &blue) {
    minimalRgbSetter(red, green, blue);
    setColorAll();
}

void MinimalLedController::setColorAll(const double &hue, const double &saturation, const double &value) {
    minimalHueToRgb(hue, saturation, value);
    setColorAll();
}

void MinimalLedController::setColorBar(const int &barIndex) {
    switch (barIndex) {
        case 0:
            for (int address = 0; address < LED_COUNT; address++) {
                ledBar_1.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
            }
            break;
        case 1:
            for (int address = 0; address < LED_COUNT; address++) {
                ledBar_2.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
            }
            break;
        case 2:
            for (int address = 0; address < LED_COUNT; address++) {
                ledBar_3.setPixelColor(address, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
            }
            break;
        default:

            break;
    }
}

void MinimalLedController::setColorBar(const int &barIndex, const int &red, const int &green, const int &blue) {
    minimalRgbSetter(red, green, blue);
    setColorBar(barIndex);
}

void MinimalLedController::setColorBar(const int &barIndex, const double &hue, const double &saturation, const double &value) {
    minimalHueToRgb(hue, saturation, value);
    setColorBar(barIndex);
}

void MinimalLedController::setColorCircle(const int &ledIndex) {
    ledBar_1.setPixelColor(ledIndex, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
    ledBar_2.setPixelColor(ledIndex, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
    ledBar_3.setPixelColor(ledIndex, _minimalRed * 0b10000000000000000 + _minimalGreen * 0b100000000 + _minimalBlue);
}

void MinimalLedController::setColorCircle(const int &ledIndex, const int &red, const int &green, const int &blue) {
    minimalRgbSetter(red, green, blue);
    setColorCircle(ledIndex);
}

void MinimalLedController::setColorCircle(const int &ledIndex, const double &hue, const double &saturation, const double &value) {
    minimalHueToRgb(hue, saturation, value);
    setColorCircle(ledIndex);
}

void MinimalLedController::minimalRgbSetter(const int &red, const int &green, const int &blue) {
    _minimalRed = red;
    _minimalGreen = green;
    _minimalBlue = blue;
}

void MinimalLedController::minimalHueToRgb(const double &hue, const double &saturation, const double &value) {
    double red, green, blue;
    int i = floor(hue * 6.0);
    double f = hue * 6.0 - i, p = value * (1.0 - saturation), q = value * (1 - f * saturation), t = value * (1 - (1 - f) * saturation);
    switch (i % 6) {
        case 0:
            red = value;
            green = t;
            blue = p;
            break;
        case 1:
            red = q;
            green = value;
            blue = p;
            break;
        case 2:
            red = p;
            green = value;
            blue = t;
            break;
        case 3:
            red = p;
            green = q;
            blue = value;
            break;
        case 4:
            red = t;
            green = p;
            blue = value;
            break;
        case 5:
            red = value;
            green = p;
            blue = q;
            break;
    }
    _minimalRed = static_cast<int> (red * 255);
    _minimalGreen = static_cast<int> (green * 255);
    _minimalBlue = static_cast<int> (blue * 255);
}

void MinimalLedController::showAll() {
    ledBar_1.show();
    ledBar_2.show();
    ledBar_3.show();
}

void SimpleLedController::flashLight() {
    setColorCircle(0, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(3, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(7, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(11, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(15, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(19, RGB_MAX, RGB_MAX, RGB_MAX);
    setColorCircle(23, RGB_MAX, RGB_MAX, RGB_MAX);
    showAll();
    delay(20);
    setColorAll(RGB_OFF, RGB_OFF, RGB_OFF);
    showAll();
    delay(20);
}

void SimpleLedController::waveUp(const int &red, const int &green, const int &blue, const int &length, const int &milliseconds) {
    rgbSetter(red, green, blue);

    for (int address = 0; address < LED_COUNT; address++) {
        if (address >= length) {
            setColorCircle(address - length, RGB_OFF, RGB_OFF, RGB_OFF);
        }
        setColorCircle(address, _red, _green, _blue);
        showAll();
        delay(milliseconds);
    }
    for (int address = LED_COUNT - length; address < LED_COUNT; address++) {
        setColorCircle(address, RGB_OFF, RGB_OFF, RGB_OFF);
        showAll();
        delay(milliseconds);
    }
}

void SimpleLedController::waveUp(const double &hue, const double &saturation, const double &value, const int &length, const int &milliseconds) {
    hueToRgb(hue, saturation, value);
    waveUp(_red, _green, _blue, length, milliseconds);
}

void SimpleLedController::waveDown(const int &red, const int &green, const int &blue, const int &length, const int &milliseconds) {
    rgbSetter(red, green, blue);

    for (int address = LED_COUNT - 1; address >= 0; address--) {
        if (address <= LED_COUNT - 1 - length) {
            setColorCircle(address + length, RGB_OFF, RGB_OFF, RGB_OFF);
        }
        setColorCircle(address, _red, _green, _blue);
        showAll();
        delay(milliseconds);
    }
    for (int address = length - 1; address >= 0; address--) {
        setColorCircle(address, RGB_OFF, RGB_OFF, RGB_OFF);
        showAll();
        delay(milliseconds);
    }
}

void SimpleLedController::waveDown(const double &hue, const double &saturation, const double &value, const int &length, const int &milliseconds) {
    hueToRgb(hue, saturation, value);
    waveDown(_red, _green, _blue, length, milliseconds);
}

void SimpleLedController::rainbowUp(const int &milliseconds, const double &value) {
    for (int offset = 0; offset < LED_COUNT; ++offset) {
        for (int address = 0; address < LED_COUNT; ++address) {
            setColorCircle(address, 1.0 * (address + offset) / 24.0, 1.0, value);
        }
        showAll();
        delay(milliseconds);
    }
}

void SimpleLedController::rainbowDown(const int &milliseconds, const double &value) {
    for (int offset = LED_COUNT - 1; offset >= 0; --offset) {
        for (int address = 0; address < LED_COUNT; ++address) {
            setColorCircle(address, 1.0 * (address + offset) / 24.0, 1.0, value);
        }
        showAll();
        delay(milliseconds);
    }
}

void SimpleLedController::breathe(const double &hue, const double &saturation, const double &value, const int &milliseconds) {

}

void SimpleLedController::rgbSetter(const int &red, const int &green, const int &blue) {
    _red = red;
    _green = green;
    _blue = blue;
}

void SimpleLedController::hueToRgb(const double &hue, const double &saturation, const double &value) {
    double red, green, blue;
    int i = floor(hue * 6.0);
    double f = hue * 6.0 - i, p = value * (1.0 - saturation), q = value * (1 - f * saturation), t = value * (1 - (1 - f) * saturation);
    switch (i % 6) {
        case 0:
            red = value;
            green = t;
            blue = p;
            break;
        case 1:
            red = q;
            green = value;
            blue = p;
            break;
        case 2:
            red = p;
            green = value;
            blue = t;
            break;
        case 3:
            red = p;
            green = q;
            blue = value;
            break;
        case 4:
            red = t;
            green = p;
            blue = value;
            break;
        case 5:
            red = value;
            green = p;
            blue = q;
            break;
    }
    _red = static_cast<int> (red * 255);
    _green = static_cast<int> (green * 255);
    _blue = static_cast<int> (blue * 255);
}
