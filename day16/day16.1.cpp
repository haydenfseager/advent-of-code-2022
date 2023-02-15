#include <bits/stdc++.h>

using namespace std;

//Valve AA has flow rate=0; tunnels lead to valves DD, II, BB


struct Valve {
    string name;
    int rate;
    vector<string> toValves;

    Valve(){
        name = "";
        rate = 0;
    }
    Valve(string n, int r, vector<string> v){
        name = n;
        rate = r;
        toValves = v;
    }
    ~Valve(){
        delete this;
    }
}

int main(){
    vector<Valve> storage;
    ifstream fin;
    fin.open("day16.test.txt");
    string line;
    string d, valve, rate, toValue;
    while(getline(fin, line)){
        vector<string> temp;
        stringstream ss(line);
        ss >> d >> valve;
        ss >> d >> d >> rate;
        ss >> d >> d >> d >> d;
        while(ss >> toValve){
            storage[valve].push_back(replace(toValve.begin(), toValve.end(), ',', ' ');
        }
    }
    for(auto [key, val]: storage){
        cout << key;
        for(auto num : val){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
