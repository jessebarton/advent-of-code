#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int finalPosition;

void loadCommands(vector<string>& vec_commands, vector<string>& vec_movement, vector<string>& vec_amount){
    fstream file;
    file.open("day2input", ios::in);

    if(file.is_open()){
        string commands;

        while(getline(file, commands)){
            vec_commands.push_back(commands);
        }
        file.close();
    }
}

void calculatePosition(vector<string>& vec_commands, vector<string>& vec_movement, vector<string>& vec_amount) {
    string delimiter = " "; 

    for(int i = 0; vec_commands.size(); i++){
        
    }
}

int main() {
    vector<string> commands;
    vector<string> movement;
    vector<string> amount;

    loadCommands(commands, movement, amount);
    calculatePosition(commands, movement, amount);

    // cout << finalPosition << endl;

    return 0;
}
