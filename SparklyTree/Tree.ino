class Tree {
    int width, height, nLights;
    Light[] light;

    Tree(int w, int h) {
      width = w;
      height = h;
      nLights = 0;

      int n = w;
      for (int l = 0; l != height; ++l) {
        nLights += n--;
      }

      light = new Light[nLight];
    }
}
