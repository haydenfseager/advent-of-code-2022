#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>

using namespace std;

int main(){
    int arr[3] = {INT_MIN, INT_MIN, INT_MIN};
    ifstream fin;
    fin.open("day1.txt");
    int input, max=0, curr_max = 0;
    string line;
    while(getline(fin, line)){
        if(line.length() == 1){
            for(int i=0; i<3; i++){
                if(arr[i] < curr_max){
                    arr[i] = curr_max;
                    break;
                }
            }
            curr_max = 0;
            continue;
        }
        stringstream ss(line);
        ss >> input;
        curr_max += input;
    }
    cout << "arr[0]= " << arr[0] << '\n';
    cout << "arr[1]= " << arr[1] << '\n';
    cout << "arr[2]= " << arr[2] << '\n';
    cout << "Max= " << arr[0] + arr[1] + arr[2] << endl;
    fin.close();
    return 0;
}
