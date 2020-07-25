//
// Created by Particle_G on 2020/7/25.
//

#ifndef GLOWSTICKCONTROLLER_LEDCONTROLLER_HPP
#define GLOWSTICKCONTROLLER_LEDCONTROLLER_HPP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define SERIAL_NUMBER 9600
#define LED_COUNT 24
#define RGB_MAX 255
#define RGB_LOW 25
#define RGB_OFF 0
#define VALUE_MAX 1.0
#define VALUE_LOW 0.1
#define VALUE_OFF 0.0
#define DEFAULT_DELAY 25

class MinimalLedController {
public:
    MinimalLedController() { _minimalRed = RGB_LOW, _minimalGreen = RGB_LOW, _minimalBlue = RGB_LOW; }

    void initController();

protected:
    void setColorAll();

    void setColorAll(const int &red, const int &green, const int &blue);

    void setColorAll(const double &hue, const double &saturation, const double &value);

    void setColorBar(const int &barIndex);

    void setColorBar(const int &barIndex, const int &red, const int &green, const int &blue);

    void setColorBar(const int &barIndex, const double &hue, const double &saturation, const double &value);

    void setColorCircle(const int &ledIndex);

    void setColorCircle(const int &ledIndex, const int &red, const int &green, const int &blue);

    void setColorCircle(const int &ledIndex, const double &hue, const double &saturation, const double &value);

    void minimalRgbSetter(const int &red, const int &green, const int &blue);

    void minimalHueToRgb(const double &hue, const double &saturation, const double &value);

    void showAll();

private:
    int _minimalRed, _minimalGreen, _minimalBlue;
    Adafruit_NeoPixel ledBar_1 = Adafruit_NeoPixel(LED_COUNT, 2, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel ledBar_2 = Adafruit_NeoPixel(LED_COUNT, 3, NEO_GRB + NEO_KHZ800);
    Adafruit_NeoPixel ledBar_3 = Adafruit_NeoPixel(LED_COUNT, 4, NEO_GRB + NEO_KHZ800);
};

class SimpleLedController : public MinimalLedController {
public:
    SimpleLedController() { _red = RGB_LOW, _blue = RGB_LOW, _green = RGB_LOW; }

    void flashLight();

    void waveUp(const int &red = RGB_LOW, const int &green = RGB_LOW, const int &blue = RGB_LOW, const int &length = LED_COUNT, const int &milliseconds = DEFAULT_DELAY);

    void waveUp(const double &hue, const double &saturation, const double &value, const int &length = LED_COUNT, const int &milliseconds = DEFAULT_DELAY);

    void waveDown(const int &red = RGB_LOW, const int &green = RGB_LOW, const int &blue = RGB_LOW, const int &length = LED_COUNT, const int &milliseconds = DEFAULT_DELAY);

    void waveDown(const double &hue, const double &saturation, const double &value, const int &length = LED_COUNT, const int &milliseconds = DEFAULT_DELAY);

    void rainbowUp(const int &milliseconds = DEFAULT_DELAY, const double &value = VALUE_LOW);

    void rainbowDown(const int &milliseconds = DEFAULT_DELAY, const double &value = VALUE_LOW);

    void breathe(const double &hue, const double &saturation, const double &value, const int &milliseconds = DEFAULT_DELAY);

protected:
    int _red, _green, _blue;

    void rgbSetter(const int &red, const int &green, const int &blue);

    void hueToRgb(const double &hue, const double &saturation, const double &value);
};


#endif //GLOWSTICKCONTROLLER_LEDCONTROLLER_HPP
