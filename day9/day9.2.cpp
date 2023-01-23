#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;
static int curr_cycle = 1;
static int reg_val = 1;

void checkPrint(){
    if(curr_cycle%40 == 0){
        cout << endl;
    }
    if(curr_cycle%40 - 1<=reg_val && curr_cycle%40 + 1>=reg_val){
        cout << "#";
    }
    else{
        cout << ".";
    }
}


int main(){
    ifstream fin;
    string line;
    fin.open("day9.txt");
    while(getline(fin, line)){
        stringstream ss(line);
        string command;
        ss >> command;
        if(command == "noop"){
            checkPrint();
            curr_cycle += 1;
        }
        else{
            int temp_val;
            ss >> temp_val;
            checkPrint();
            curr_cycle += 1;
            reg_val += temp_val;
            checkPrint();
            curr_cycle += 1;
        }
    }
    return 0;
}
