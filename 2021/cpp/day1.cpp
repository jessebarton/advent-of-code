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
         int previousDepth = vec_depths[p];
         int newDepth = vec_depths[p+1];

         if(previousDepth < newDepth){
            counter++;
         } else {
            cout << "decrease" << endl;
         }
   }
}

int main(){
   vector<int> depths;

   loadDepth(depths);
   compareDepths(depths);

   cout << counter << "\n";
}