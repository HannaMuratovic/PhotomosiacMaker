#ifndef __READDIR_H_INCLUDED__
#define __READDIR_H_INCLUDED__

void readDIR(const char *dir_name, vector<string> &filename_v){};

#ifndef __RGBAVERAGE_H_INCLUDED__
#define __RGBAVERAGE_H_INCLUDED__

void rgbAverage(CImg<int> image, int &tile_average[3]){};

#ifndef __TILE_H_INCLUDED__
#define __TILE_H_INCLUDED__

struct tile {};

#ifndef __CREATEMAINTILES_H_INCLUDED__
#define __CREATEMAINTILES_H_INCLUDED__

void createMainTiles(CImg<int> image, vector<tile> &main_tile_averages, int td){};

#ifndef __BESTTILEMATCH_H_INCLUDED__
#define __BESTTILEMATCH_H_INCLUDED__

int* bestTileMatch(vector<tile> main_tile_averages, vector<tile> sub_tile_averages){};

#ifndef __CREATEMOSIAC_H_INCLUDED__
#define __CREATEMOSIAC_H_INCLUDED__

void createMosiac (vector<tile>  sub_tile_averages, int* match_indices[], int tile_width,
int tile_height, int org_width, int org_height){};
