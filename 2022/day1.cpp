#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> get_input(string file_name) {
    vector<vector<int>> data;
    ifstream file(file_name);
    string line;
    while (getline(file, line)) {
        vector<int> elf;
        stringstream ss(line);
        string meal;
        while (getline(ss, meal, '\n')) {
            elf.push_back(stoi(meal));
        }
        data.push_back(elf);
    }
    return data;
}

int part_one(vector<vector<int>> data) {
    int maximum = 0;
    for (auto elf : data) {
        int sum = 0;
        for (auto meal : elf) {
            sum += meal;
        }
        if (sum > maximum) {
            maximum = sum;
        }
    }
    return maximum;
}


int part_two(vector<vector<int>> data) {
    vector<int> sums;
    for (auto elf : data) {
        int sum = 0;
        for (auto meal : elf) {
            sum += meal;
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end(), greater<int>());
    return sums[0] + sums[1] + sums[2];
}

int main() {
    string file_name = "day1input.txt";
    vector<vector<int>> data = get_input(file_name);
    cout << "The answer to part one is " << part_one(data) << endl;
    cout << "The answer to part two is " << part_two(data) << endl;
    return 0;
}