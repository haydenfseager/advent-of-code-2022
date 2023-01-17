#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int main(){
    set<char> s;
    string line;
    ifstream fin;
    fin.open("day6.txt");
    getline(fin, line);
    stringstream ss(line);
    for(int i=0, j=13; j<line.length(); i++, j++){
        for(int k=i; k<=j; k++){
            if(s.count(line[k])){
                break;
            }
            else{
                s.insert(line[k]);
            }
            if(k==j){
                cout << j+1 << endl;
                return 0;
            }
        }
        s.clear();
    }
    return 0;
}
