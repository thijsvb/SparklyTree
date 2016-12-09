#include "Arduino.h"
#include "Tree.h"
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

Tree::Tree(int w, int h, int p) {
 width = w;
 height = h;
 nLights = 0;

 int n = w;
 for (int l = 0; l != height; ++l) {
   nLights += n--;
 }

 Tree::lightAt(int l, int n) {

 }


}
