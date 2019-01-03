void rgbAverage(Mat image, int &tile_average[3]){
  int image_size = image.cols*image.rows;
  int blue, green, red = 0;
  for (int j = 1; j <= image.cols; j++) {
    for (int k = 1; k <= image.rows; k++) {
      Vec3b intensity = image.at<Vec3b>(k, j);
      blue += intensity.val[0];
      green += intensity.val[1];
      red += intensity.val[2];
    }
  }
  tile_average[0] = red/image_size;
  tile_average[1] = green/image_size;
  tile_average[2] = blue/image_size;
}
