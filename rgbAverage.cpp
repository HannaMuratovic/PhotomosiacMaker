void rgbAverage(CImg<int> image, int &tile_average[3]){
  int image_size = image.width()*image.height();
  int blue, green, red = 0;
  for (int j = 1; j <= image.width(); j++) {
    for (int k = 1; k <= image.height(); k++) {
      red += image(j, k, 0, 0);
      green += image(j , k, 0, 1);
      blue += image(j, k, 0, 2);
    }
  }
  tile_average[0] = red/image_size;
  tile_average[1] = green/image_size;
  tile_average[2] = blue/image_size;
}
