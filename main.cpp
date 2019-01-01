#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

struct tile {
  string filepath;
  int average[3];
}

void rgb_average(Mat image, int &average[3]){

}

void main(){
   const char* directory_name = "C:\\Users\\HANNA\\Desktop\\Photos\\Dorm Photos";
   vector<string> file_names;
   readDIR(directory_name, file_names);

   Mat tile_image;
   tile tile_data;
   tile store_tiles[file_names.size()];
   for (int i = 0; i < file_names.size(); i++) {
     tile_image = imread(file_names[i], 1);
     tile.filepath = file_names[i];
     rgb_average(tile_image, tile.average);
    }
}
