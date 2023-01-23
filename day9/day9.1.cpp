#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;
static int curr_cycle = 1;
static int reg_val = 1;
static map<int, int> m;
static int arr[240];

void addMoment(int cycle, int val){
    m.insert(make_pair(cycle, val));
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
            addMoment(curr_cycle, reg_val);
            curr_cycle += 1;
        }
        else{
            int temp_val;
            ss >> temp_val;
            addMoment(curr_cycle, reg_val);
            curr_cycle += 1;
            reg_val += temp_val;
            addMoment(curr_cycle, reg_val);
            curr_cycle += 1;
        }
    }
    int output = 0;
    for(auto [cycle, val]: m){
        if(cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220){
            cout << "Cycle= " << cycle << " val= " << val << endl;
            output += cycle*val;
        }
    }
    cout << "Output= " << output << endl;
    return 0;
}
