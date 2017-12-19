#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int stripPin = 9;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, stripPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

int j = 0;
void loop() {
  for(int i=0; i!=strip.numPixels(); ++i) {
    uint32_t c;
    if((i+j)%3 == 0) {
      c = strip.Color(255, 0, 0);
    }
    else if((i+j)%3 == 1) {
      c = strip.Color(0, 255, 0);
    }
    else if((i+j)%3 == 2) {
      c = strip.Color(0, 0, 255);
    }
    strip.setPixelColor(i, c);
  }
  strip.show();
  ++j;
  delay(100);
}

