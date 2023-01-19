#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <functional>

using namespace std;


struct File {
    string name;
    int size;

    File() {
        name = "";
        size = -1;
    }
    ~File(){}
    File(string n, int s) {
        name = n;
        size = s;
    }
};

struct Directory {
    string name;
    vector<Directory> folders;
    vector<File> files;

    Directory(){
        name = "";
    }
    ~Directory(){}

    Directory(string n){
        name = n;
    }

    void addDirectory(string n){
        Directory temp = Directory(n);
        folders.push_back(temp);
    }

    void addFile(string n, int s){
        File temp = File(n, s);
        files.push_back(temp);
    }
    int files_size(){
        int output = 0;
        for(int i=0; i<files.size(); i++){
            output += files[i].size;
        }
        return output;
    }

    void printContents(){
        if(folders.size() == 0 && files.size() == 0){
            return;
        }
        for(int i=0; i<folders.size(); i++){
            cout << "\t" << folders[i].name << endl;
        }
        for(int i=0; i<files.size(); i++){
            cout << "\t" << files[i].name << endl;
        }
        cout << endl;
    }
};

int BFS(Directory d){
    int output = 0;
    queue<Directory> q;
    q.push(d);
    while(!q.empty()){
        auto curr_dir = q.front();
        q.pop();
        output += curr_dir.files_size();
        for(auto child : curr_dir.folders){
            q.push(child);
        }
    }
    return output;
}

void runCode(){
    string line, type;
    ifstream fin;
    stack<reference_wrapper<Directory>> dir_stack;
    Directory home = Directory("/");
    dir_stack.push(ref(home));

    fin.open("day7.txt");
    while(getline(fin, line)){
        stringstream ss(line);
        ss >> type;
        if(type == "$"){
            string command;
            ss >> command;
            if(command == "cd"){
                string command2;
                ss >> command2;
                if(command2 == "/"){
                    while(dir_stack.top().get().name != "/"){
                        if(dir_stack.empty()){
                            break;
                        }
                        dir_stack.pop();
                    }
                }
                else if(command2 == ".."){
                    dir_stack.pop();
                }
                else{
                    for(int i=0; i<dir_stack.top().get().folders.size(); i++){
                        if(command2 == dir_stack.top().get().folders[i].name){
                            dir_stack.push(dir_stack.top().get().folders[i]);
                        }
                    }
                }
            }
            else if(command == "ls"){
                dir_stack.top().get().printContents();
            }
        }
        else if(type == "dir"){
            string dir_name;
            ss >> dir_name;
            dir_stack.top().get().addDirectory(dir_name);
        }
        else {
            string filename;
            int size = stoi(type);
            ss >> filename;
            dir_stack.top().get().addFile(filename, size);
        }
    }
    while(dir_stack.top().get().name != "/"){
        dir_stack.pop();
    }
    int currSize = BFS(dir_stack.top().get());
    vector<int> storage;
    queue<Directory> q;
    q.push(dir_stack.top().get());
    while(!q.empty()){
        auto curr_dir = q.front();
        q.pop();
        int temp = BFS(curr_dir);
        if(currSize - temp < 40000000){
            storage.push_back(temp);
        }
        for(int i=0; i<curr_dir.folders.size(); i++){
            q.push(curr_dir.folders[i]);
        }
    }
    int min = INT_MAX;
    for(auto num : storage){
        if(num < min){
            min = num;
        }
    }
    cout << "Output= " << min << endl;
}

int main(){
    runCode();
    return 0;
}
