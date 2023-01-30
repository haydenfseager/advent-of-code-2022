#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> tail_map;
int row = 1000, col = 1000;

void addTailPos(pair<int, int> p){
    if(tail_map.count(p)){
        return;
    }
    else{
        tail_map[p] = 1;
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
    int xstart = row/2;
    int ystart = col/2;
    pair<int, int> head = make_pair(xstart, ystart);
    pair<int, int> tail = make_pair(xstart, ystart);
    addTailPos(tail);
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
        for(int i=0; i<num; i++){
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
            bool isClose = false;
            for(auto [dx, dy]: dir){
                if((head.first + dx) == tail.first && (head.second + dy) == tail.second){
                    isClose = true;
                    break;
                }
            }
            if(isClose){
                continue;
            }
            else{
                if(head.first == tail.first || head.second == tail.second){
                    moveTail(head, tail, vert);
                }
                else{
                    moveTail(head, tail, diag);
                }
            }
            addTailPos(tail);
        }
    }
    fin.close();
}

int main(){
    run();
    int output = 0;
    for(auto [key,val] : tail_map){
        output += 1;
    }
    cout << "Output= " << output << endl;
    return 0;
}
