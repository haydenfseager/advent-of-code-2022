#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("day1.txt");
    int input, max=0, curr_max = 0;
    string line;
    while(getline(fin, line)){
        if(line.length() == 1){
            curr_max = 0;
            continue;
        }
        stringstream ss(line);
        ss >> input;
        curr_max += input;
        if(curr_max > max){
            max = curr_max;
        }
    }
    cout << "Max= " << max << endl;
    fin.close();
    return 0;
}
