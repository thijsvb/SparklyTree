#ifndef Tree_h
#define Tree_h
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

#include "Arduino.h"

class Tree {
  public:
    Tree(int w, int h, int p);
    NeoPixelBus lights;
    int width, height, nLights;
    int lightAt(int l, int n);
    void set(int l, int n, int r, int g, int b);
    //int[3] get(int l, int n);
};

#endif
