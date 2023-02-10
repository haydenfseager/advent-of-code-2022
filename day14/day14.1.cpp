#include <bits/stdc++.h>

using namespace std;

int rows = 1000, cols = 1000;
pair<int, int> start = make_pair(0, 500);
static int bottom = INT_MIN;

vector<pair<int, int>> dirs {
    {1, 0},
    {1, -1},
    {1, 1}
};

vector<vector<char>> grid(rows, vector<char>(cols, '.'));

void printGrid(){
    for(int i=0; i<11; i++){
        for(int j=cols/2 -10; j<cols/2 + 10; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}


void addSand(pair<int, int> input){
    int i=0;
    if(input.first > bottom){
        return;
    }
    for(auto [dy, dx]: dirs){
        pair<int, int> curr = input;
        curr.first += dy;
        curr.second += dx;
        if(grid[curr.first][curr.second] == '.'){
            addSand(curr);
            break;
        }
        else if(i==2){
            grid[input.first][input.second] = 'o';
        }
        i++;
    }
    return;
}

void findBottom(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == '#' && i > bottom){
                bottom = i;
            }
        }
    }
}

int countSand(){
    int numSand = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == 'o'){
                numSand++;
            }
        }
    }
    return numSand;
}

int main(){
    ifstream fin;
    fin.open("day14.txt");
    string line;
    while(getline(fin, line)){
        replace(line.begin(), line.end(), '-', ' ');
        replace(line.begin(), line.end(), '>', ' ');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        int rowValFrom=0, colValFrom=0, rowValTo=0, colValTo=0;
        while(ss){
            if(rowValFrom == 0){
                ss >> colValFrom >> rowValFrom >> colValTo >> rowValTo;
            }
            else{
                ss >> colValTo >> rowValTo;
            }
            //Need to see which direction we fill. Try to always do i++
            if(rowValFrom == rowValTo){
                //Fill same row, different cols
                for(int i=min(colValFrom, colValTo); i<=max(colValFrom, colValTo); i++){
                    grid[rowValFrom][i] = '#';
                }
            }
            else{
                for(int i=min(rowValFrom, rowValTo); i<=max(rowValFrom, rowValTo); i++){
                    grid[i][colValFrom] = '#';
                }
            }
            colValFrom = colValTo;
            rowValFrom = rowValTo;
        }
    }
    findBottom();
    int i=10000;
    while(i--){
        addSand(start);
    }
    cout << "Output= " << countSand();
    return 0;
}
