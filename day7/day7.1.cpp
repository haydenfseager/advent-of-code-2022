#include <iostream>
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
            cout << "Empty container" << endl;
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

void BFSprint(Directory d){
    queue<Directory> q;
    q.push(d);
    while(!q.empty()){
        auto curr_dir = q.front();
        q.pop();
        curr_dir.printContents();
        for(int i=0; i<curr_dir.folders.size(); i++){
            q.push(curr_dir.folders[i]);
        }
    }
}

void runCode(){
    stack<reference_wrapper<Directory>> dir_stack;
    Directory home = Directory("/");
    dir_stack.push(ref(home));
    string line, type;
    ifstream fin;
    fin.open("day7.txt");
    while(getline(fin, line)){
        stringstream ss(line);
        ss >> type;
        if(type == "$"){
            string command;
            ss >> command;
            if(command == "cd"){
                cout << "execute cd" << endl;
                string command2;
                ss >> command2;
                if(command2 == "/"){
                    while(dir_stack.top().name != "/"){
                        cout << "home while loop exe" << endl;
                        if(dir_stack.empty()){
                            cout << "Error: dir_stack empty" << endl;
                            break;
                        }
                        dir_stack.pop();
                    }
                }
                else if(command2 == ".."){
                    cout << "\tPopping Stack" << endl;
                    dir_stack.pop();
                }
                else{
                    for(int i=0; i<dir_stack.top().folders.size(); i++){
                        if(command2 == dir_stack.top().folders[i].name){
                            dir_stack.push(dir_stack.top().folders[i]);
                        }
                    }
                }
            }
            else if(command == "ls"){
                dir_stack.top().printContents();
            }
        }
        else if(type == "dir"){
            cout << "execute dir" << endl;
            string dir_name;
            ss >> dir_name;
            dir_stack.top().addDirectory(dir_name);
        }
        else {
            cout << "execute addfile" << endl;
            string filename;
            int size = stoi(type);
            ss >> filename;
            dir_stack.top().addFile(filename, size);
        }
    }
    while(!dir_stack.empty()){
        cout << dir_stack.top().name << endl;
        dir_stack.top().printContents();
        if(dir_stack.top().name == "/"){
            break;
        }
        dir_stack.pop();
    }
    cout << dir_stack.top().name << endl;
    dir_stack.top().printContents();
    for(int i=0; i<dir_stack.top().folders.size(); i++){
        dir_stack.top().folders[i].printContents();
    }
    //BFSprint(dir_stack.top());
    //int output = 0;
    //dir_stack.top().printContents();
    //queue<Directory> q;
    //q.push(dir_stack.top());
    //while(!q.empty()){
    //    auto curr_dir = q.front();
    //    curr_dir.printContents();
    //    q.pop();
    //    int temp = BFS(curr_dir);
    //    if(temp < 100000){
    //        output += temp;
    //    }
    //    for(int i=0; i<curr_dir.folders.size(); i++){
    //        q.push(curr_dir.folders[i]);
    //    }
    //}
    //cout << "Output= " << output << endl;
}

int main(){
    //Directory test = Directory("/");
    //test.addDirectory("the1");
    //test.addFile("hello2345.txt", 150);
    //test.folders[0].addFile("hello1", 100);
    //test.printContents();
    //test.folders[0].printContents();
    //
    runCode();
    return 0;
}
