#include <bits/stdc++.h>

using namespace std;

int rows = 1000, cols = 1000;
pair<int, int> start = make_pair(500, 0);

vector<vector<char>> grid(rows, vector<char>(cols, '.'));

void printGrid(){
    for(int i=0; i<11; i++){
        for(int j=cols/2 -10; j<cols/2 + 10; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main(){
    ifstream fin;
    fin.open("day14.test.txt");
    string line;
    while(getline(fin, line)){
        replace(line.begin(), line.end(), '-', ' ');
        replace(line.begin(), line.end(), '>', ' ');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        int rowValFrom=0, colValFrom=0, rowValTo=0, colValTo=0;
        while(ss){
            if(rowValFrom == 0){
                cout << "EXE IF" << endl;
                ss >> colValFrom >> rowValFrom >> colValTo >> rowValTo;
                printf("%d, %d, %d, %d\n", colValFrom, rowValFrom, colValTo, rowValTo);
            }
            else{
                cout << "EXE ELSE" << endl;
                ss >> colValTo >> rowValTo;
                printf("%d, %d\n", colValTo, rowValTo);
            }
            //Need to see which direction we fill. Try to always do i++
            if(colValFrom == colValTo){
                //Fill same col, different rows
                for(int i=min(colValFrom, colValTo); i<max(colValFrom, colValTo); i++){
                    grid[rowValFrom][i] = '#';
                }
            }
            else{
                for(int i=min(rowValFrom, rowValTo); i<max(rowValFrom, rowValTo); i++){
                    grid[i][colValFrom] = '#';
                }
            }
            colValFrom = colValTo;
            rowValFrom = rowValTo;
        }
    }
    printGrid();

    return 0;
}
