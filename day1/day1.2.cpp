#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int arr[3] = {INT_MIN, INT_MIN, INT_MIN};
    ifstream fin;
    fin.open("day1.txt");
    int input, max=0, curr_max = 0;
    string line;
    while(getline(fin, line)){
        if(line.length() == 1){
            sort(arr, arr+3);
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
    cout << "Max= " << arr[0] + arr[1] + arr[2] << endl;
    fin.close();
    return 0;
}
