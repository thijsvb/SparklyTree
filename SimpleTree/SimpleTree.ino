const int tree = 11;
const int star = 6;

void setup() {
 pinMode(tree, OUTPUT);
 pinMode(star, OUTPUT);

 delay(2000);
 for(float a=0; a<=PI/6; a+=0.002) {
  analogWrite(star, sin(a)*255);
  delay(5);
 }
 for (int i=0; i!=256; ++i) {
  analogWrite(tree, i);
  delay(5);
 }
 for (int i=255;; --i) {
  analogWrite(tree, i);
  delay(5);
  if(i <= 255*0.66) break;
 }
}

void loop() {
  float x = float(millis())/100;
  
  double flicker = sin(x)/4 + sin(x/PI)/4 + 0.5;
  analogWrite(star, flicker * 255);

  double pulse = sin(x/4)/3 + 0.66;
  analogWrite(tree, pulse * 255);
}
