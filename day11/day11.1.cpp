#include <bits/stdc++.h>

using namespace std;


struct Monkey{
    queue<int> items;
    char operation;
    string operationVal;
    int numInspected;
    int divisibleBy;
    pair<int, int> nextMonkeyVals;

    Monkey(){
        numInspected = 0;
        divisibleBy = 0;
        nextMonkeyVals.first = 0;
        nextMonkeyVals.second = 0;
        operation = '-';
        operationVal = "-";
    }
    void setOperation(char o){
        operation = o;
    }
    void setOperationVal(string v){
        operationVal = v;
    }
    int nextMonkeyVal(){
        if(operationVal == "old"){
            if(operation == '*'){
                items.front() *= items.front();
            }
            else{
                items.front() += items.front();
            }
        }
        else{
            if(operation == '*'){
                items.front() *= stoi(operationVal);
            }
            else {
                items.front() += stoi(operationVal);
            }
        }
        items.front() /= 3;
        if(items.front() % divisibleBy == 0){
            return nextMonkeyVals.second;
        }
        else{
            return nextMonkeyVals.first;
        }
    }
    void printMonkey(){
        queue<int> temp;
        cout << "items= ";
        while(!items.empty()){
            cout << items.front() << " ";
            temp.push(items.front());
            items.pop();
        }
        while(!temp.empty()){
            items.push(temp.front());
            temp.pop();
        }
        cout << endl;
        cout << "Operation= " << operation << endl;
        cout << "OperationVal= " << operationVal << endl;
        cout << "divisibleBy= " << divisibleBy << endl;
        cout << "nextMonkeyVals= " << nextMonkeyVals.first << " " << nextMonkeyVals.second << endl;
        cout << endl;
    }
};

void run(){
    vector<Monkey> monkeys;
    ifstream fin;
    fin.open("day11.txt");
    string line;
    int i=8;
    while(i--){
        Monkey* m = new Monkey();
        //Monkey 0:
        getline(fin, line);
        cout << line << endl;

        //Starting items: 59, 74, 65, 86
        getline(fin, line);
        cout << line << endl;

        stringstream ss(line);
        string d;
        string num;
        ss >> d >> d;
        while(getline(ss, num, ',')){
            cout << "num= " << num << endl;
            m->items.push(stoi(num));
        }
        ss.str("");
        ss.clear();
        getline(fin, line);
        cout << line << endl;
        ss << line;
        //Operation: new = old * 19
        string o;
        string opv;
        ss >> d >> d >> d >> d >> o >> opv;
        cout << "o= " << o << endl;
        cout << "opv= " << opv << endl;
        m->operation = o[0];
        m->operationVal = opv;
        cout << "m.operation= " << m->operation << endl;
        cout << "m.operationVal= " << m->operationVal << endl;
        //Test: divisible by 7
        getline(fin, line);
        cout << line << endl;
        ss.str("");
        ss.clear();
        ss << line;
        ss >> d >> d >> d;
        int db;
        ss >> db;
        cout << "db = " << db << endl;
        m->divisibleBy = db;
        //If true: throw to monkey 6
        getline(fin, line);
        cout << line << endl;
        ss.str("");
        ss.clear();
        ss << line;
        ss >> d >> d >> d >> d >> d;
        int trueVal, falseVal;
        ss >> trueVal;
        m->nextMonkeyVals.second = trueVal;
        cout << "trueVal= " << trueVal;
        //If false: throw to monkey 2
        getline(fin, line);
        cout << line << endl;
        ss.str("");
        ss.clear();
        ss << line;
        ss >> d >> d >> d >> d >> d;
        ss >> falseVal;
        m->nextMonkeyVals.first = falseVal;
        cout << "falseVal= " << falseVal;
        //newline
        getline(fin, line);
        cout << line << endl;
        m->printMonkey();
        monkeys.push_back(*m);
    }
    for(auto m: monkeys){
        m.printMonkey();
    }
    //loop through every item each monkey has and get the next monkey val
    //store the front of the list in a temp var and move it next monkey val
    //pop the fron of the items queue
    for(int i=0; i<20; i++){
        for(int j=0; j<8; j++){
            while(!monkeys[j].items.empty()){
                int toMonkey = monkeys[j].nextMonkeyVal();
                cout << "toMonkey= " << toMonkey << endl;
                int temp = monkeys[j].items.front();
                cout << "temp= " << temp << endl;
                monkeys[j].items.pop();
                monkeys[toMonkey].items.push(temp);
                monkeys[j].numInspected++;
            }
        }
    }
    int first = 0, second = 0;
    for(int i=0; i<8; i++){
        if(monkeys[i].numInspected > first || monkeys[i].numInspected > second){
            if(first < second){
                first = monkeys[i].numInspected;
            }
            else{
                second = monkeys[i].numInspected;
            }
        }
    }
    cout << "first= " << first << " " << "second= " << second << endl;
    cout << first*second << endl;
}

int main(){
    run();
    return 0;
}
