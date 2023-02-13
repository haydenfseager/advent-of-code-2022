#include <bits/stdc++.h>

using namespace std;


int rows = 1e7, cols = 1e7;
vector<vector<char>> grid(rows, vector<char>(cols, '.'));
map<pair<int,int>,int> source_map;

vector<pair<int, int>> dirs {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};


void propagate(pair<int, int> cords, int num){
    if(num < 0){
        return;
    }
    if(grid[cords.first][cords.second] != 'S' && grid[cords.first][cords.second] != 'B'){
        grid[cords.first][cords.second] = '#';
    }
    for(auto [dx, dy] : dirs){
        pair<int, int> curr = cords;
        curr.first += dx;
        curr.second += dy;
        propagate(curr, num-1);
    }
}

void count(int row){
    int output = 0;
    for(int i=0; i<cols; i++){
        if(grid[row][i] == '#'){
            ++output;
        }
    }
    cout << "Output= " << output;
}

void myReplace(string &s){
    for(char c: s){
        if(c < '0' || c > '9'){
            if(c == '-'){
                continue;
            }
            replace(s.begin(), s.end(), c, ' ');
        }
    }
}

void printGrid(){
    int val = 25;
    for(int i=rows/2 - val; i<rows/2 + val; i++){
        for(int j=cols/2 - val; j<cols/2 + val; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ifstream fin;
    cout << "test" << endl;
    fin.open("day15.txt");
    string line;
    string d;
    char c;
    string source_col, source_row, beacon_col, beacon_row;
    int scol, srow, bcol, brow;
    int i=1;
    /*while(i--){
        getline(fin,line);
        cout << line << endl;
        stringstream ss(line);
        ss >> d >> d >> source_col >> source_row;
        ss >> d >> d >> d >> d >> beacon_col >> beacon_row;
        myReplace(source_row);
        myReplace(source_col);
        myReplace(beacon_row);
        myReplace(beacon_col);
        scol = stoi(source_col);
        srow = stoi(source_row);
        bcol = stoi(beacon_col);
        brow = stoi(beacon_row);
        cout << scol << endl;
        cout << srow << endl;
        cout << bcol << endl;
        cout << brow << endl;
        srow += 2000;
        scol += 2000;
        brow += 2000;
        bcol += 2000;
        grid[srow][scol] = 'S';
        grid[brow][bcol] = 'B';
        int dist = abs(srow - brow) + abs(scol - bcol);
        cout << "dist= " << dist << endl;
        source_map[make_pair(srow,scol)] = dist;
    }
    for(auto [key, val] : source_map){
        printf("Key= %d,%d Val= %d\n", key.first, key.second, val);
        propagate(key, val);
    }
    //printGrid();
    count(2000000 + 2000);*/
    fin.close();

    return 0;
}
