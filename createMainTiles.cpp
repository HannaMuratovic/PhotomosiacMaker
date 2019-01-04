void createMainTiles(CImg<int> image, vector<tile> &main_tile_averages, int td){
  tile main_tile_data;
  for (int i = 0; i <= image.width(); i += td){
    for (int j = 0; j <= image.height(); j += td){
      CImg<int> cropped_image = image.get_crop(i*td, j*td, 0, 0, (i+1)*td, (j+1)*td, 0, 3);
      rgbAverage(cropped_image, main_tile_data.average);
      main_tile_averages.push_back(main_tile_data);
    }
  }
}
