#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

struct tile {
  string filepath;
  int average[3];
}

void rgb_average(Mat image, int &tile_average[3]){
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

void create_main_tiles(Mat image, vector<int> &main_tile_averages, int td){
  for (int i = 0; i <= image.cols; i += td){
    for (int j = 0; j <= image.rows; j += td){
      Rect roi = Rect(i*td, j*td, (i+1)*td, (j+1)*td);
      Mat image_roi = image(roi);
      
    }
  }
}



void main(){
   const char* directory_name = "C:\\Users\\HANNA\\Desktop\\Photos\\Dorm Photos";
   vector<string> file_names;
   readDIR(directory_name, file_names);

   Mat tile_image;
   tile tile_data;
   tile store_tiles[file_names.size()];
   for (int i = 0; i < file_names.size(); i++){
     tile_data.filepath = file_names[i];
     tile_image = imread(file_names[i], 1);
     tile.filepath = file_names[i];
     rgb_average(tile_image, tile_data.average);
     store_tiles[i] = tile_data;
    }

    string main_image_path = "";
    Mat main_image = imread(main_image_path);

}
