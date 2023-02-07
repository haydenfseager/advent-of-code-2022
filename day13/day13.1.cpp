#include <bits/stdc++.h>
#include <variant>

using namespace std;

struct Packet{
    vector<variant<int,Packet>> list;

    Packet(){}

    Packet(string line){
        stack<Packet*> storage;
        Packet* ptr = this;
        storage.push(ptr);
        for(int i=1; i<line.length(); i++){
            if(line[i] == '['){
                Packet* temp = new Packet();
                ptr->list.push_back(*temp);
                storage.push(temp);
                ptr = temp;
            }
            else if(line[i] == ']'){
                storage.pop();
                ptr = storage.top();
            }
            else if(line[i] >= '0' && line[i] <= '9'){
                if(line[i] == '1' && line[i+1] == '0'){
                    ptr->list.push_back(10);
                    i++;
                }
                else{
                    ptr->list.push_back(line[i] - '0');
                }
            }
        }
    }

    //Print could work but idk rn
    void print(){
        for(int i=0; i<list.size(); i++){
            if(holds_alternative<int>(list[i])){
                cout << get<int>(list[i]) << ",";
            }
            else{
                cout << "[";
                get<Packet>(list[i]).print();
            }
        }
        cout << "]";
    }

};

//bool comparePackets(Packet p1, Packet p2){
//    
//}

int main(){
    ifstream fin;
    fin.open("day13.test.txt");
    string line;
    string temp1, temp2;
    int i=1;
    while(i--){
        getline(fin, line);
        line = line.substr(0, line.length()-1);
        if(line.length() == 1){
            continue;
        }
        else{
            temp1 = line;
            Packet* temp = new Packet(line);
            //temp->print();
            cout << endl;
            //getline(fin, line);
            //temp2 = line;
            //packet_pairs.push_back(make_pair(temp1, temp2));
        }
    }
    fin.close();
    return 0;
}
