#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>
#include <math.h>
#include <limits.h>
#include <mosiac.h>

using namespace cv;
using namespace std;

void main(){
   const char* directory_name = "C:\\Users\\HANNA\\Desktop\\Photos\\Dorm Photos";
   string main_image_path = "hello";
   vector<string> file_names;
   readDIR(directory_name, file_names);

   Mat tile_image;
   tile tile_data;
   int max_height = 0;
   int max_width = 0;
   vector<tile> store_tiles[file_names.size()];
   for (int i = 0; i < file_names.size(); i++){
     tile_data.filepath = file_names[i];
     tile_image = imread(file_names[i], 1);
     rgbAverage(tile_image, tile_data.average);
     store_tiles[i] = tile_data;

     if (tile_image.rows > max_height){
       max_height = tile_image.rows;
     }
     if (tile_image.cols > max_width){
       max_width = tile_image.cols
     }
    }

    Mat main_image = imread(main_image_path, 1);
    int tile_dimension = 50;
    int num_rows = (main_image.rows/tile_dimension);
    int num_cols = (main_image.cols/tile_dimension);
    vector<tile> store_main_tiles;
    createMainTiles(main_image, store_main_tiles, tile_dimension);
    int* pbest_match = bestTileMatch(store_main_tiles, store_tiles);
    createMosiac(store_tiles, pbest_match, max_width, max_height, num_cols, num_rows);
}
