class Tree {
  public:
    int width, height, nLights;

    Tree(int w, int h, int p) {
      width = w;
      height = h;
      nLights = 0;

      int n = w;
      for (int l = 0; l != height; ++l) {
        nLights += n--;
      }

      
    }
};


