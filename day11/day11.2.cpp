#include <bits/stdc++.h>

using namespace std;

int highestVal = 1;

struct Monkey{
    queue<long long> items;
    char operation;
    string operationVal;
    long long numInspected;
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
                items.front() *= stoll(operationVal);
            }
            else {
                items.front() += stoll(operationVal);
            }
        }
        items.front() %= highestVal;
        if(items.front() % divisibleBy == 0){
            //cout << "\tThrew to Monkey " << nextMonkeyVals.second << endl;
            return nextMonkeyVals.second;
        }
        else{
            //cout << "\tThrew to Monkey " << nextMonkeyVals.first << endl;
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
        getline(fin, line); //Monkey 0:

        getline(fin, line); //Starting items: 59, 74, 65, 86
        stringstream ss(line);
        string d;
        string num;
        ss >> d >> d;
        while(getline(ss, num, ',')){
            m->items.push(stoi(num));
        }
        ss.str("");
        ss.clear();

        getline(fin, line); //Operation: new = old * 19
        ss << line;
        string o;
        string opv;
        ss >> d >> d >> d >> d >> o >> opv;
        m->operation = o[0];
        m->operationVal = opv;
        ss.str("");
        ss.clear();

        getline(fin, line); //Test: divisible by 7
        int db;
        ss << line;
        ss >> d >> d >> d >> db;
        m->divisibleBy = db;
        highestVal *= db;
        ss.str("");
        ss.clear();

        getline(fin, line); //If true: throw to monkey 6
        int trueVal, falseVal;
        ss << line;
        ss >> d >> d >> d >> d >> d >> trueVal;
        m->nextMonkeyVals.second = trueVal;
        ss.str("");
        ss.clear();

        getline(fin, line); //If false: throw to monkey 2
        ss << line;
        ss >> d >> d >> d >> d >> d >> falseVal;
        m->nextMonkeyVals.first = falseVal;

        getline(fin, line); //newline

        //m->printMonkey(); //Use this for testing
        monkeys.push_back(*m);
    }
    cout << "highestVal= " << highestVal << endl;
    for(int i=1; i<=10000; i++){
        //cout << "---------------------------" << endl;
        //cout << "\tRound " << i << endl;
        //cout << "---------------------------" << endl;
        if(i==1 || i==20 || i%1000 == 0){
            cout << "\ti= " << i << endl;
        }
        for(int j=0; j<monkeys.size(); j++){
            //cout << "Monkey " << j << endl;
            while(!monkeys[j].items.empty()){
                int toMonkey = monkeys[j].nextMonkeyVal();
                monkeys[toMonkey].items.push(monkeys[j].items.front());
                monkeys[j].items.pop();
                monkeys[j].numInspected += 1;
            }
            if(i==1 || i==20 || i%1000 == 0){
                cout << j << ": " << monkeys[j].numInspected << endl;
            }
        }
    }
    long long first = 0, second = 0;
    for(int i=0; i<monkeys.size(); i++){
        if(monkeys[i].numInspected > first || monkeys[i].numInspected > second){
            if(first < second){
                first = monkeys[i].numInspected;
            }
            else{
                second = monkeys[i].numInspected;
            }
        }
    }
    cout << "first= " << first << "second= " << second << endl;
    cout << "Output= " << first*second << endl;
}

int main(){
    run();
    return 0;
}
