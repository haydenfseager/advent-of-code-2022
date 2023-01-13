#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

//A - Rock
//B - Paper
//C - Scissor
//
//X - Rock
//Y - Paper
//Z - Scissor
string arr[3][3] = {
    {"Draw", "Win", "Loss"},
    {"Loss", "Draw", "Win"},
    {"Win", "Loss", "Draw"}
};

int main(){
    int total = 0;
    ifstream fin;
    fin.open("day2.txt");
    string line;
    char input, response;
    while(getline(fin, line)){
        stringstream ss(line);
        ss >> input >> response;
        int in = input - 'A';
        int res = response - 'X';
        string result = arr[in][res];
        if(result == "Win"){
            total += 6 + res + 1;
        }
        else if(result == "Loss"){
            total += res + 1;
        }
        else if(result == "Draw"){
            total += 3 + res + 1;
        }
    }
    cout << "Total= " << total << '\n';
    return 0;
}
