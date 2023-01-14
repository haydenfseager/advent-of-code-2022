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
    //Loss, Draw, Win
    {"Scissors", "Rock", "Paper"},
    {"Rock", "Paper", "Scissors"},
    {"Paper", "Scissors", "Rock"}
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
        int row = input - 'A';
        int col = response - 'X';
        string result = arr[row][col];
        if(result == "Rock"){
            total += col*3 + 1;
        }
        else if(result == "Paper"){
            total += col*3 + 2;
        }
        else if(result == "Scissors"){
            total += col*3 + 3;
        }
    }
    cout << "Total= " << total << '\n';
    return 0;
}
