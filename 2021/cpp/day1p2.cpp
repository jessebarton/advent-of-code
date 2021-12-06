#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int counter = 0;

void loadDepth(vector<int>& vec_depths) {
   fstream file;
   file.open("day1input", ios::in);

   if (file.is_open()){
      string depth;

      while(getline(file, depth)){
         int num = stoi(depth);

         vec_depths.push_back(num);
      }
      file.close();
   }
}

void compareDepths(vector<int>& vec_depths) {
   for(int p = 0; p < vec_depths.size(); p++){
        int first = vec_depths[p];
        int second = vec_depths[p+1];
        int third = vec_depths[p+2];
        int fourth = vec_depths[p+1];
        int fifth = vec_depths[p+2];
        int sixth = vec_depths[p+3];

        int firstWindow = first + second + third;
        int secondWindow = fourth + fifth + sixth;

        // cout << firstWindow << endl;
        // cout << secondWindow << endl;

        if(firstWindow < secondWindow) {
            counter++;
        }

   }
}

int main() {
    vector<int> depths;

    loadDepth(depths);
    compareDepths(depths);

    cout << counter << "\n";

    return 0;
}