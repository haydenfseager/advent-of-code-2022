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
        if(high1 >= low2 && low1 <= low2){ //E.g. 0-2,1-3
            output += 1;
        }
        else if(high2 >= low1 && low2 <= low1){ //E.g. 1-3,0-2
            output += 1;
        }
        else if(low2 >= low1 && high2 <= high1){ //E.g. 1-8,2-7
            output += 1;
        }
        else if(low1 >= low2 && high1 <= high2){ //E.g. 2-7,1-8
            output += 1;
        }
    }
    cout << "output= " << output;
    return 0;
}
