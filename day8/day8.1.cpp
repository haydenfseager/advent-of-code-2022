#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

static int storage[99][99];

bool isVisible(int x, int y){
    int score = 0;
    vector<tuple<int, int>> dir = {
        {1, 0}, 
        {-1, 0},
        {0, 1}, 
        {0, -1}
    };
    for(auto [dx, dy] : dir){
        int curr_x = x, curr_y = y;
        while(true){
            curr_x += dx;
            curr_y += dy;
            if(curr_x == -1 || curr_x == 99 || curr_y == -1 || curr_y == 99){
                return true;
            }
            else if(storage[curr_x][curr_y] >= storage[x][y]){
                break;
            }
        }
    }
    return false;
}

void printArr(int (&arr)[99][99]){
    for(int i=0; i<99; i++){
        for(int j=0; j<99; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main(){
    string line;
    char c;
    ifstream fin;
    fin.open("day8.txt");
    int i=0;
    while(getline(fin, line)){
        for(int j=0; j<line.length()-1; j++){
            storage[i][j] = line[j] - '0';
        }
        i++;
    }
    int arr[99][99];
    memset(arr, 0, sizeof(arr));
    int output = 0;
    for(int i=0; i<99; i++){
        for(int j=0; j<99; j++){
            if(isVisible(i, j)){
                output += 1;
                arr[i][j] = 1;
            }
        }
    }
    cout << "Output= " << output << endl;
    return 0;
}
