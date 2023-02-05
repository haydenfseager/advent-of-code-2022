#include <bits/stdc++.h>

using namespace std;

//int rows = 5, cols = 8; for testing the example case
int rows = 41, cols = 162;
vector<vector<int>> maze(rows, vector<int>(cols, 0));
vector<vector<int>> dist(rows, vector<int>(cols));
vector<vector<bool>> visited(rows, vector<bool>(cols));

vector<tuple<int, int>> dirs {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int BFS(pair<int, int> pos, pair<int, int> end){
    queue<pair<int, int>> q;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            visited[i][j] = false;
            dist[i][j] = INT_MAX;
        }
    }
    q.push(pos);
    visited[pos.first][pos.second] = true;
    dist[pos.first][pos.second] = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        for(auto [dx, dy]: dirs){
            pair<int, int> temp = make_pair(curr.first + dx, curr.second + dy);
            if(temp.first < 0 || temp.first > rows-1 || temp.second < 0 || temp.second > cols-1){
                continue;
            }
            else if(maze[curr.first][curr.second]+1 >= maze[temp.first][temp.second] && !visited[temp.first][temp.second]){
                dist[temp.first][temp.second] = dist[curr.first][curr.second] + 1;
                visited[temp.first][temp.second] = true;
                if(temp.first == end.first && temp.second == end.second){
                    return dist[temp.first][temp.second];
                }
                else{
                    q.push(temp);
                }
            }
        }
    }
    return INT_MAX;
}

int main(){
    ifstream fin;
    fin.open("day12.txt");
    string line;
    int i=0;
    pair<int, int> start, end;
    while(getline(fin, line)){
        for(int j=0; j<line.length()-1; j++){
            if(line[j] != 'E' && line[j] != 'S'){
                maze[i][j] = line[j] - 'a';
            }
            else{
                if(line[j] == 'S'){
                    start.first = i;
                    start.second = j;
                    cout << "Start= " << start.first << ", " << start.second << endl;
                    maze[i][j] = 0;
                }
                else{
                    end.first = i;
                    end.second = j;
                    cout << "End= " << end.first << ", " << end.second << endl;
                    maze[i][j] = 25;
                }
            }
        }
        i++;
    }
    int output = INT_MAX;
    for(int j=0; j<rows; j++){
        for(int k=0; k<cols; k++){
            if(maze[j][k] == 0){
                int temp = BFS(make_pair(j, k), end);
                if(temp < output){
                    output = temp;
                }
            }
        }
    }
    cout << "Output= " << output << endl;
    return 0;
}
