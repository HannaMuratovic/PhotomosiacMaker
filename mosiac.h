#ifndef __READDIR_H_INCLUDED__
#define __READDIR_H_INCLUDED__
#ifndef __RGBAVERAGE_H_INCLUDED__
#define __RGBAVERAGE_H_INCLUDED__
#ifndef __TILE_H_INCLUDED__
#define __TILE_H_INCLUDED__
#ifndef __CREATEMAINTILES_H_INCLUDED__
#define __CREATEMAINTILES_H_INCLUDED__
#ifndef __BESTTILEMATCH_H_INCLUDED__
#define __BESTTILEMATCH_H_INCLUDED__
#ifndef __CREATEMOSIAC_H_INCLUDED__
#define __CREATEMOSIAC_H_INCLUDED__

void readDIR(const char *dir_name, vector<string> &filename_v){};

struct tile {};

void rgbAverage(Mat image, int &tile_average[3]){};

void createMainTiles(Mat image, vector<tile> &main_tile_averages, int td){};

int* bestTileMatch(vector<tile> main_tile_averages, vector<tile> sub_tile_averages){};

void createMosiac (vector<tile>  sub_tile_averages, int* match_indices[], int tile_width,
int tile_height, int org_width, int org_height){};
