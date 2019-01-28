#ifndef __MOSIACS_H_INCLUDED__
#define __MOSIACS_H_INCLUDED__

void readDIR(const char *dir_name, vector<string> &filename_v){};

void rgbAverage(CImg<int> image, int &tile_average[3]){};

struct tile {};

void createMainTiles(CImg<int> image, vector<tile> &main_tile_averages, int td){};

int* bestTileMatch(vector<tile> main_tile_averages, vector<tile> sub_tile_averages){};

void createMosiac (vector<tile>  sub_tile_averages, int* match_indices[], int tile_width,
int tile_height, int org_width, int org_height){};

#ENDIF
