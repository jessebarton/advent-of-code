#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int powerConsumption; // Found by multiplying the gamma rate by the epsilon rate.

int gammaRate; // Most Common Bit
int epsilonRate; // Least Common Bit

void loadBinaryNumbers(std::vector<std::string> &vec_binNums) {
    std::fstream file;
    file.open("day3input", std::ios::in);

    if (file.is_open())
    {
        std::string commands;

        while (getline(file, commands))
        {
            vec_binNums.push_back(commands);
        }
        file.close();
    }
}

void identify(std::string i, int zero, int one, int index) {
    if(i[index] == 0){
        zero = zero + 1;
    } else {
        one = one + 1;
    }
}

void calculate(std::vector<std::string> &vec_binNums) {
    for (auto i : vec_binNums) {
        int zero;
        int one;
        identify(i, zero, one, 0);
        std::cout << i[1];
        std::cout << i[2];
        std::cout << i[3];
        std::cout << i[4];
        std::cout << i[5];
        std::cout << i[6];
        std::cout << i[7];
        std::cout << i[8];
        std::cout << i[9];
        std::cout << i[10];
        std::cout << i[11];
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::string> binNums;

    loadBinaryNumbers(binNums);
    calculate(binNums);



    return 0;
}