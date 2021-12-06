#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
   fstream file;
   file.open("tpoint.txt",ios::out);
   file.open("tpoint.txt",ios::in);
   if (file.is_open()){
      string tp;
      while(getline(file, tp)){
         cout << tp << "\n";
      }
      file.close();
   }
}