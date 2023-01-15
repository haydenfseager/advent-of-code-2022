#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

//Check first vs. second and then second vs. first

int main(){
    int low1, low2, high1, high2, output = 0;
    string line;
    char c;
    ifstream fin;
    fin.open("day4.txt");
    while(getline(fin,line)){
        stringstream ss(line);
        ss >> low1 >> c >> high1 >> c >> low2 >> c >> high2;
        cout << low1 << " " << high1 << " " << low2 << " " << high2 << endl;
        if(low2 >= low1 && high2 <= high1){
            output += 1;
        }
        else if(low1 >= low2 && high1 <= high2){
            output += 1;
        }
    }
    cout << "output= " << output;
    return 0;
}
