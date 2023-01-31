#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> tail_map;
int row = 1000, col = 1000;
static int node_val = 0;

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

//void print5x5(pair<int, int> &h){
//    for(int i=h.first-2; i<=h.first+2; i++){
//        for(int j=h.second-2; j<=h.second+2; j++){
//            cout << testV[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

void addTailPos(pair<int, int> p){
    if(tail_map.count(p)){
        return;
    }
    else{
        tail_map[p] = 1;
    }
}

bool isClose(pair<int, int> &h, pair<int, int> &t){
    for(auto [dx, dy] : dir){
        if(h.first + dx == t.first && h.second + dy == t.second){
            return true;
        }
    }
    return false;
}
bool isVert(pair<int, int> &h, pair<int, int> &t){
    if(h.first == t.first || h.second == t.second){
        return true;
    }
    return false;
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
};

struct Node {
    Node* next;
    int num;
    pair<int, int> p;
    Node(){
        num = node_val;
        node_val++;
        p.first = row/2;
        p.second = col/2;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    int length;

    LinkedList(){
        head == NULL;
        tail == NULL;
        length = 0;
    }

    void add(Node* n){
        if(!head){
            head = n;
            tail = n;
        }
        else{
            Node* ptr = head;
            while(ptr->next){
                ptr = ptr->next;
            }
            ptr->next = n;
            tail = n;
        }
    }
    void update(){
        //Take in new value for head
        //Update the head value to the new value
        //For the next knot call the isClose function to check if its still close the current knot
        //If its close dont do anything and break from the loop
        //If it isn't close, check if need to move diag or vert then call move knot
        Node* ptr = head;
        while(ptr->next){
            if(isClose(ptr->p, ptr->next->p)){
                break;
            }
            else{
                if(isVert(ptr->p, ptr->next->p)){
                    moveTail(ptr->p, ptr->next->p, vert);
                }
                else{
                    moveTail(ptr->p, ptr->next->p, diag);
                }
            }
            ptr = ptr->next;
        }
    }
};


void run(){
    int xstart = row/2;
    int ystart = col/2;
    Node* head = new Node();
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    Node* n6 = new Node();
    Node* n7 = new Node();
    Node* n8 = new Node();
    Node* n9 = new Node();
    LinkedList* list = new LinkedList();
    list->add(head);
    list->add(n1);
    list->add(n2);
    list->add(n3);
    list->add(n4);
    list->add(n5);
    list->add(n6);
    list->add(n7);
    list->add(n8);
    list->add(n9);
    addTailPos(make_pair(list->tail->p.first, list->tail->p.second));
    string line;
    ifstream fin;
    fin.open("day9.txt");
    while(getline(fin, line)){
        stringstream ss(line);
        char command;
        int num;
        ss >> command >> num;
        for(int i=0; i<num; i++){
            if(command == 'U'){
                list->head->p.first -= 1;
            }
            else if(command == 'D'){
                list->head->p.first += 1;
            }
            else if(command == 'L'){
                list->head->p.second -= 1;
            }
            else if(command == 'R'){
                list->head->p.second += 1;
            }
            list->update();
            addTailPos(list->tail->p);
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
