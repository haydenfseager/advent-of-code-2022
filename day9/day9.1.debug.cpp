#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> tail_map;
map<pair<int, int>, int> head_map;
int row = 1000, col = 1000;
vector<vector<char>> testV(row, vector<char>(col, '-'));

void print5x5(pair<int, int> &h){
    for(int i=h.first-2; i<=h.first+2; i++){
        for(int j=h.second-2; j<=h.second+2; j++){
            cout << testV[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void addToTestV(pair<int, int> &h, pair<int, int> &t){
    if(h.first == t.first && h.second == t.second){
        testV[h.first][h.second] = '*';
    }
    else{
        testV[h.first][h.second] = 'H';
        testV[t.first][t.second] = 'T';
    }
    print5x5(h);
    fill(testV.begin(), testV.end(), vector<char>(col, '-'));
}

void addTailPos(pair<int, int> p){
    if(tail_map.count(p)){
        return;
    }
    else{
        tail_map[p] = 1;
    }
}

void addHeadPos(pair<int, int> p){
    if(head_map.count(p)){
        head_map[p] += 1;
    }
    else{
        head_map[p] =  1;
    }
}

void moveTail(pair<int, int> &h, pair<int, int> &t, vector<tuple<int, int>> &dirs){
    int xmin = INT_MAX;
    int ymin = INT_MAX;
    for(auto [dx, dy]: dirs){
        int curr_x = t.first + dx;
        int curr_y = t.second + dy;
        if(abs(xmin-h.first) >= abs(curr_x-h.first) && abs(ymin-h.second) >= abs(curr_y-h.second)){
            xmin = curr_x;
            ymin = curr_y;
        }
    }
    t.first = xmin;
    t.second = ymin;
}

void run(){
    int test=0;
    int xstart = 500;
    int ystart = 500;
    pair<int, int> head = make_pair(xstart, ystart);
    pair<int, int> tail = make_pair(xstart, ystart);
    addHeadPos(head);
    addTailPos(tail);
    addToTestV(head, tail);
    string line;
    ifstream fin;
    fin.open("day9.txt");
    vector<tuple<int, int>> dir = {
        {0, 0},
        {0, -1},
        {0, 1},
        {1, 0},
        {1, 1},
        {1, -1},
        {-1, 0},
        {-1, 1},
        {-1, -1},
    };
    vector<tuple<int, int>> diag = {
        {1, 1},
        {-1, 1},
        {-1, -1},
        {1, -1},
    };
    vector<tuple<int, int>> vert = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    while(getline(fin, line)){
        stringstream ss(line);
        char command;
        int num;
        ss >> command >> num;
        cout << "\tcommand = " << command << " " << "num= " << num << endl;
        for(int i=0; i<num; i++){
            cout << "i= " << i << endl;
            if(command == 'U'){
                head.first -= 1;
            }
            else if(command == 'D'){
                head.first += 1;
            }
            else if(command == 'L'){
                head.second -= 1;
            }
            else if(command == 'R'){
                head.second += 1;
            }
            addToTestV(head, tail);
            bool isClose = false;
            for(auto [dx, dy]: dir){
                if((head.first + dx) == tail.first && (head.second + dy) == tail.second){
                    isClose = true;
                    break;
                }
            }
            if(isClose){
                cout << "Only moved head!" << endl;
                addHeadPos(head);
                continue;
            }
            else{
                cout << "moved head and tail!" << endl;
                if(head.first == tail.first || head.second == tail.second){
                    moveTail(head, tail, vert);
                }
                else{
                    moveTail(head, tail, diag);
                }
            }
            addHeadPos(head);
            addTailPos(tail);
            addToTestV(head, tail);
            test += 1;
        }
    }
    cout << "exited while loop" << endl;
    cout << "test= " << test << endl;
    fin.close();
}

int main(){
    run();
    vector<vector<int>> tailArr(row, vector<int>(col, 0));
    vector<vector<int>> headArr(row, vector<int>(col, 0));
    int output = 0;
    for(auto [key,val] : tail_map){
        tailArr[key.first][key.second] = 1;
        output += 1;
    }
    for(auto [key,val] : head_map){
        headArr[key.first][key.second] = 1;
    }
    //for(int i=0; i<row; i++){
    //    for(int j=0; j<col; j++){
    //        cout << tailArr[i][j];
    //    }
    //    cout << " ";
    //    //for(int j=0; j<col; j++){
    //    //    cout << headArr[i][j];
    //    //}
    //    //cout << endl;
    //}
    cout << "Output= " << output << endl;
    return 0;
}
