#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int stripPin = 9;
const int levels = 10;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, stripPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop() {
  for (int i=levels-1; i!=-1; --i) {
    for (int j=0; j!=i+1; ++j) {
      int r = random(205,305)%255;
      strip.setPixelColor(mapPixel(i,j), r, 255-r, 0);
      strip.show();
      delay(100);
    }
  }

  clearStrip();
}

/*
 * For the animations I'd like to think of the position of the lights in terms of level and number (l,n).
 * With level going from top to bottom, number from left to right, making the top light (0,0) and (9,0) the bottom left.
 * But because the LED-strip zigzags from bottom to top (at least, thats the configuration I chose because it was less of a mess),
 * a mapping is needed to use the level and number system.
 * This mapping will work for an even number of levels with the strip starting bottom left or for an odd number of pixels with the strip starting bottom right.
 * If you'd like to make your tree differently, you're weird. But I'll show you how in the mapping function.
 * 
 * As for how the mapping function works; it's a bit annoying, but I'll try to explain.
 * First we add up all the numbers from 0 up to l (l being the level of the pixel we're trying to find)
 * and we subtrackt that from the index of the last pixel (which is one less than the total number of pixels).
 * The formula for adding all numbers from zero to i is; i*(i+1)/2, you'll see it used a couple of times. (thanks Wolfram Alpha)
 * Now we have the index for the firs or last pixel in level l, depending on whether it's an even or odd level (because the strip zig zags).
 * So now we just have to subtrackt the pixel number n or (l-n), because the lth level will have pixels numbers 0 up to l.
 * At this point jus try drawing a numbered diagram if you really want to understand it.
 */
int mapPixel(int l, int n) {
  if(!(l < levels && n <= l)) return -1; // you goofed up
  
  int total = levels*(levels+1)/2;
  int pixelNr = l*(l+1)/2;
  pixelNr = total - 1 - pixelNr;
  
  if(l%2 == 0) {                  //If you're weird, change the 0 to a 1 in this line
    pixelNr = pixelNr - n;
  } else {
    pixelNr = pixelNr - (l-n);
  }
  
  return pixelNr;
}

void clearStrip() {
  for(int i=0; i!=strip.numPixels(); ++i) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

