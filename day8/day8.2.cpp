#include <iostream>
#include <climits>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

static int storage[99][99];

int findScore(int x, int y){
    int output = 1;
    vector<tuple<int, int>> dir = {
        {1, 0}, 
        {-1, 0},
        {0, 1}, 
        {0, -1}
    };
    for(auto [dx, dy] : dir){
        int curr_score = 0;
        int curr_x = x, curr_y = y;
        while(true){
            curr_x += dx;
            curr_y += dy;
            if(curr_x == -1 || curr_x == 99 || curr_y == -1 || curr_y == 99){
                break;
            }
            curr_score++;
            if(storage[curr_x][curr_y] >= storage[x][y]){
                break;
            }
        }
        output *= curr_score;
    }
    return output;
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
    int max_score = INT_MIN;
    for(int i=0; i<99; i++){
        for(int j=0; j<99; j++){
            int curr_score = findScore(i, j);
            if(curr_score > max_score){
                max_score = curr_score;
            }
        }
    }
    cout << "Output= " << max_score << endl;
    return 0;
}
