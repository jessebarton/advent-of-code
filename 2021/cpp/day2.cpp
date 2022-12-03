#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int aim;
int hPosition;
int finalPosition;
int depth;
int down;
int up;

std::vector<std::string> split(std::string str, std::string token)
{
    std::vector<std::string> result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != std::string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

void loadCommands(std::vector<std::string> &vec_commands)
{
    std::fstream file;
    file.open("day2input", std::ios::in);

    if (file.is_open())
    {
        std::string commands;

        while (getline(file, commands))
        {
            vec_commands.push_back(commands);
        }
        file.close();
    }
}

void calculatePosition(std::vector<std::string> &vec_commands)
{
    for (auto i : vec_commands)
    {
        std::vector<std::string> s = split(i, " ");

        if(s[0] == "down") {
            // depth = depth + stoi(s[1]);
            aim = aim + std::stoi(s[1]);
        }

        if(s[0] == "up") {
            // depth = depth - stoi(s[1]);
            aim = aim - std::stoi(s[1]);
        }

        if(s[0] == "forward") {
            hPosition = hPosition + std::stoi(s[1]);
            depth = depth + (aim * std::stoi(s[1]));
        }
    }

    std::cout << "Horizontal Position: " << hPosition << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    
    // depth = up - down;
    finalPosition = hPosition * depth;

    std::cout << "Final Position: " << finalPosition << std::endl;
}

int main()
{
    std::vector<std::string> commands;

    loadCommands(commands);
    calculatePosition(commands);

    return 0;
}
