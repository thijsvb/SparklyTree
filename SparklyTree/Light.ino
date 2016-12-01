class Light {
    int R, G, B;

    Light() {
      R = 255;
      G = 255;
      B = 255;
    }

    void set(int red, int green, int blue) {
      R = red;
      G = green;
      B = blue;
    }

    int[3] get() {
      return {R, G, B};
    }

    int red() {
      return R;
    }
    void red(int inRed) {
      set(inRed, G, B);
    }

    int green() {
      return G;
    }
    void green(int inGreen) {
      set(R, inGreen, B);
    }

    int blue() {
      return B;
    }
    void blue(int inBlue) {
      set(R, G, inBlue);
    }
}

