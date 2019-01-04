#include <CImg.h>
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>
#include <math.h>
#include <limits.h>
#include <mosiac.h>

using namespace cimg_library;
using namespace std;

//cimg::imagemagick_path("D:\\ImageMagick-6.9.2-Q16\\convert.exe");

void main(){
   const char* directory_name = "C:\\Users\\HANNA\\Desktop\\Photos\\Dorm Photos";
   string main_image_path = "hello";
   vector<string> file_names;
   readDIR(directory_name, file_names);

   // Mat tile_image;
   tile tile_data;
   int max_height = 0;
   int max_width = 0;
   vector<tile> store_tiles[file_names.size()];
   for (int i = 0; i < file_names.size(); i++){
     tile_data.filepath = file_names[i];
     //tile_image = imread(file_names[i], 1);
     CImg<int> tile_image(file_names[i]);
     rgbAverage(tile_image, tile_data.average);
     store_tiles[i] = tile_data;

     if (tile_data.height() > max_height){
       max_height = tile_data.height();
     }
     if (tile_data.width() > max_width){
       max_width = tile_data.width();
     }
    }

    //Mat main_image = imread(main_image_path, 1);
    // CImg<int> main_image(main_image_path);
    // int tile_dimension = 50;
    // int num_rows = (main_image.height()/tile_dimension);
    // int num_cols = (main_image.width()/tile_dimension);
    // vector<tile> store_main_tiles;
    // createMainTiles(main_image, store_main_tiles, tile_dimension);
    // int* pbest_match = bestTileMatch(store_main_tiles, store_tiles);
    // createMosiac(store_tiles, pbest_match, max_width, max_height, num_cols, num_rows);
}
