#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <vector>

using namespace std;

void readDIR(const char *dir_name, vector<string> &filename_v){
  DIR *directory;
  struct dirent  *entry;
  struct stat folder_info;
  //open directory
  directory = opendir(dir_name);
  if (directory != NULL) {
    // print all the files and directories within directory
    while ((entry = readdir(directory)) != NULL) {
      // if file is an actual folder and not just '.' or '..'
      if (entry->d_name[0] != '.'){
        string path = string(dir_name) + "\\" + string(entry->d_name);
        if (stat(path.c_str(), &folder_info) == 0) {
          // ignores sub-directories
          if( folder_info.st_mode & S_IFREG ){
            filename_v.push_back(path);
          }
        }
      }
    }
  closedir(directory);
  } else {
  /* could not open directory */
  perror ("");
  return;
  }
}

main() {
 const char* directory_name = "C:\\Users\\HANNA\\Desktop\\Photos\\Dorm Photos";
 vector<string> file_names;
 readDIR(directory_name, file_names);
  return 0;
}
