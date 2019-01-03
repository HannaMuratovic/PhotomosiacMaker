void createMosiac (vector<tile>  sub_tile_averages, int* match_indices[], int tile_width,
int tile_height, int org_width, int org_height){
  int pm_width = tile_width*org_width;
  int pm_height = tile_height*org_height;
  Mat mosiac(pm_height, pm_width, CV_8UC3, Scalar(0, 0, 0));

  for (int i = 0; i < org_width; i++) {
    for (int j = 0; j < org_height; j++) {
      int index = match_indices[i*(org_width)+j];
      Mat tile = imread(sub_tile_averages[index].name, 1);
      tile.copyTo(mosiac(Rect(i*tile_width,i*j,(i+1)*tile_width, (j+1)*tile_height)));
    }
  }
  namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Display window", mosiac);
}
