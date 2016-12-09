#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>
#include <Tree.h>

Tree tree;
const int treePin = 4;

void setup() {
  tree = new Tree(10, 10, treePin);
}

void loop() {
  // put your main code here, to run repeatedly:

}
