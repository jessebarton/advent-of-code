#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int aim;
int hPosition;
int finalPosition;
int depth;
int down;
int up;

vector<string> split(string str, string token)
{
    vector<string> result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != string::npos)
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

void loadCommands(vector<string> &vec_commands)
{
    fstream file;
    file.open("day2input", ios::in);

    if (file.is_open())
    {
        string commands;

        while (getline(file, commands))
        {
            vec_commands.push_back(commands);
        }
        file.close();
    }
}

void calculatePosition(vector<string> &vec_commands)
{
    for (auto i : vec_commands)
    {
        vector<string> s = split(i, " ");

        if(s[0] == "down") {
            // depth = depth + stoi(s[1]);
            aim = aim + stoi(s[1]);
        }

        if(s[0] == "up") {
            // depth = depth - stoi(s[1]);
            aim = aim - stoi(s[1]);
        }

        if(s[0] == "forward") {
            hPosition = hPosition + stoi(s[1]);
            depth = depth + (aim * stoi(s[1]));
        }
    }

    cout << "Horizontal Position: " << hPosition << endl;
    cout << "Depth: " << depth << endl;
    
    // depth = up - down;
    finalPosition = hPosition * depth;

    cout << "Final Position: " << finalPosition << endl;
}

int main()
{
    vector<string> commands;

    loadCommands(commands);
    calculatePosition(commands);

    return 0;
}
