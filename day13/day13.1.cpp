#include <bits/stdc++.h>
#include <variant>

using namespace std;

static int packetNum;

struct Packet{
    vector<variant<int,Packet*>> list;
    int num = packetNum;

    Packet(){
        num = packetNum;
        packetNum++;
    }


    Packet(string line){
        line = line.substr(1,line.length()-3);
        num = packetNum;
        packetNum++;
        stack<Packet*> storage;
        storage.push(this);
        Packet* ptr = storage.top();
        for(int i=0; i<line.length(); i++){
            if(line[i] == '['){
                cout << "Created new packet" << endl;
                Packet* temp = new Packet();
                ptr->list.push_back(temp);
                storage.push(temp);
            }
            else if(line[i] == ']'){
                cout << "Popped from storage" << endl;
                storage.pop();
            }
            else if(line[i] >= '0' && line[i] <= '9'){
                //cout << "found num" << endl;
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

};

void printPacket(Packet* p){
    cout << "[";
    for(int i=0; i<p->list.size(); i++){
        if(holds_alternative<int>(p->list[i])){
            cout << get<int>(p->list[i]);
            if(i != p->list.size()-1){
                cout << ",";
            }
        }
        else{
            printPacket(get<Packet*>(p->list[i]));
        }
    }
    cout << "]";
}

int comparePackets(Packet* p1, Packet* p2){
    for(int i=0; i<min(p1->list.size(), p2->list.size()); i++){
        if(holds_alternative<int>(p1->list[i]) && holds_alternative<int>(p2->list[i])){
            //both ints
            int leftVal = get<int>(p1->list[i]);
            int rightVal = get<int>(p2->list[i]);
            if(leftVal < rightVal){
                return 1;
            }
            else if(leftVal > rightVal){
                return 0;
            }
            else{
                continue;
            }
        }
        else if(holds_alternative<Packet*>(p1->list[i]) && holds_alternative<Packet*>(p2->list[i])){
            //both packets
            Packet* newP1 = get<Packet*>(p1->list[i]);
            Packet* newP2 = get<Packet*>(p2->list[i]);
            int val = comparePackets(newP1,newP2);
            if(val == 1){
                return 1;
            }
            else if(val == 0){
                return 0;
            }
            else{
                continue;
            }
        }
        else{
            //One is int one is packet
            //Must find out which one is which
            int val;
            if(holds_alternative<int>(p1->list[i])){
                //p1 is int
                string tempString = "[" + to_string(get<int>(p1->list[i])) + "]";
                Packet* temp = new Packet(tempString);
                val = comparePackets(temp, p2);
            }
            else{
                //p2 is int
                string tempString = "[" + to_string(get<int>(p2->list[i])) + "]";
                Packet* temp = new Packet(tempString);
                val = comparePackets(p1, temp);
            }
            if(val == 1){
                return 1;
            }
            else if(val == 0){
                return 0;
            }
            else{
                continue;
            }
        }
    }
    if(p1->list.size() < p2->list.size()){
        return 1;
    }
    else if(p1->list.size() > p2->list.size()){
        return 0;
    }
    else{
        return 2;
    }
}

int main(){
    packetNum = 0;
    ifstream fin;
    fin.open("day13.test.txt");
    string line;
    int output = 0;
    int i = 1;
    while(getline(fin, line)){
        //getline(fin, line);
        if(line.length() == 1){
            i++;
            continue;
        }
        else{
            Packet* temp1 = new Packet(line);
            printPacket(temp1);
            getline(fin, line);
            Packet* temp2 = new Packet(line);
            printPacket(temp2);
            output += comparePackets(temp1, temp2)*i;
        }
    }
    cout << "Output= " << output << endl;
    fin.close();
    return 0;
}
