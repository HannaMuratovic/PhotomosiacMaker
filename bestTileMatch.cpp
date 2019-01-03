int* bestTileMatch(vector<tile> main_tile_averages, vector<tile> sub_tile_averages){
  int *best_match = new int[main_tile_averages.size()];
  int distance = INT_MAX;

  for (int i = 0; i < main_tile_averages.size(); i++) {
    for (int j = 0; j < sub_tile_averages.size(); j++){
      int red_diff = main_tile_averages[i].average[0]-sub_tile_averages[j].average[0];
      int green_diff = main_tile_averages[i].average[1]-sub_tile_averages[j].average[1];
      int blue_diff = main_tile_averages[i].average[2]-sub_tile_averages[j].average[2];
      int new_distance = sqrt(pow(red_diff,2)+pow(green_diff,2)+pow(blue_diff,2));

      if (new_distance < distance){
        int best_match_index = j;
        distance = new_distance;
      }
    }
    best_match[i] = best_match_index;
  }
  return best_match;
}
