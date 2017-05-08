/* 
 * Arduino Code for Aurora Dress
 * By Vera Wei Wang, wei.wang@cca.edu
 */
 
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define BNO055_SAMPLERATE_DELAY_MS (100)
#define N_PIXELS  44  // Number of pixels in strand
#define LED_PIN    1  // The pin to which NeoPixel LED strand is connected
Adafruit_BNO055 bno = Adafruit_BNO055();
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Prepare for multi-tasking
class Pattern {
 public:
  Pattern(int cycle) : cycle_(cycle) {}
  void Enable() { if (state_ < 0) state_ = 0; }
  void Disable() { state_ = -1; }
  virtual void Show() = 0;
  void Run() {
    if (state_ == -1) return;
    Show(); strip.show(); ++state_; state_ %= cycle_;
  };
 protected:
  int state_ = -1, cycle_ = -1;
};

// Rainbow (or aurora) effect
class RainbowCycle : public Pattern {
 public:
  static const int kCursion = 8;
  RainbowCycle(int cycle) : Pattern(cycle) {}
  void Show() override {
    if (state_ < kCursion) { return; }
    for (int i = 0; i < strip.numPixels(); ++i) {
      if (state_ - kCursion < 127) strip.setBrightness(state_ - kCursion);
      else strip.setBrightness(255 - state_ + kCursion);
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + state_ - kCursion) & 255));
    }
  }
};

Pattern* patterns[] = {new RainbowCycle(256 + RainbowCycle::kCursion)};

// Theatre-style crawling lights.
void theaterChase(uint32_t c) {
  for (int j = 0; j < 10; ++j) {
    strip.setBrightness(127 - j * 10);
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);
      }
      strip.show(); delay(50);
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);
      }
    }
  }
}

// Fill the lights one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// turn off lights
void Out() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
}

void setup() {
  strip.begin();
  strip.show(); 
  bno.begin();
  bno.setExtCrystalUse(true);
}

void loop() {
  int accelZ = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER).z(); // acceleration in z (vertical) direction, m/s^2
  int rotateZ = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE).z(); // angular velocity in z (vertical) direction, rps
  if (accelZ > 15) { // jumps
    patterns[0]->Disable();
    theaterChase(strip.Color(random(0, 255), random(0, 255), random(0, 255)));
  } else { 
    if (rotateZ > 2 || rotateZ < -2) { // rotate
      colorWipe(strip.Color(255, 255, 255), 50);
    } else { // motionless
      patterns[0]->Enable();
    }
  }
  for (int i = 0; i < sizeof(patterns) / sizeof(Pattern*); ++i) patterns[i]->Run();
  delay(25);
}
