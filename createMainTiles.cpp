void createMainTiles(Mat image, vector<tile> &main_tile_averages, int td){
  tile main_tile_data;
  for (int i = 0; i <= image.cols; i += td){
    for (int j = 0; j <= image.rows; j += td){
      Rect roi = Rect(i*td, j*td, (i+1)*td, (j+1)*td);
      Mat image_roi = image(roi);
      rgbAverage(image_roi, main_tile_data.average);
      main_tile_averages.push_back(main_tile_data);
    }
  }
}
