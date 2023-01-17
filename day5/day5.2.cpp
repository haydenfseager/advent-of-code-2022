#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

//[H]                 [Z]         [J]
//[L]     [W] [B]     [G]         [R]
//[R]     [G] [S]     [J] [H]     [Q]
//[F]     [N] [T] [J] [P] [R]     [F]
//[B]     [C] [M] [R] [Q] [F] [G] [P]
//[C] [D] [F] [D] [D] [D] [T] [M] [G]
//[J] [C] [J] [J] [C] [L] [Z] [V] [B]
//[M] [Z] [H] [P] [N] [W] [P] [L] [C]
// 1   2   3   4   5   6   7   8   9 

stack<char> s1, s2, s3, s4, s5, s6, s7, s8, s9;
vector<stack<char>*> stack_arr = {&s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9};
vector<vector<char>> arr = 
{{'H','L','R','F','B','C','J','M'},
{'D','C','Z'},
{'W','G','N','C','F','J','H'},
{'B','S','T','M','D','J','P'},
{'J','R','D','C','N'},
{'Z','G','J','P','Q','D','L','W'},
{'H','R','F','T','Z','P'},
{'G','M','V','L'},
{'J','R','Q','F','P','G','B','C'}};
//This is the reverse order but I couldn't copy and paste in reverse


int main(){
    //initial state of stacks
    for(int i=0; i<arr.size(); i++){
        for(int j=stack_arr.size()-1; j>=0; j--){
            stack_arr[i]->push(arr[i][j]);
        }
    }
    string line, word;
    int num, from, to;
    char c;
    vector<char> temp;
    ifstream fin;
    fin.open("day5.txt");
    while(getline(fin, line)){
        stringstream ss(line);
        ss >> word >> num >> word >> from >> word >> to;
        for(int i=0; i<num; i++){
            c = stack_arr[from-1]->top();
            stack_arr[from-1]->pop();
            temp.push_back(c);
        }
        for(int i=temp.size()-1; i>=0; i--){
            stack_arr[to-1]->push(temp[i]);
        }
        temp.clear();
    }
    for(int i=0; i<stack_arr.size(); i++){
        cout << stack_arr[i]->top();
    }
    fin.close();
    return 0;
}
