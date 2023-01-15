#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>


//The length will always be an even number

using namespace std;

map<char, int> m1, m2, m3;

int main(){
    int output = 0, length1, length2, length3;
    string line1, line2, line3;
    ifstream fin;
    fin.open("day3.txt");
    while(!fin.eof()){
        getline(fin, line1);
        getline(fin, line2);
        getline(fin, line3);
        length1 = line1.length()-1;
        length2 = line2.length()-1;
        length3 = line3.length()-1;
        m1.clear();
        m2.clear();
        m3.clear();
        for(int i=0; i<length1; i++){
            if(m1.count(line1[i])){
                m1[line1[i]]++;
            }
            else{
                m1.insert(make_pair(line1[i], 1));
            }
        }
        for(int i=0; i<length2; i++){
            if(m2.count(line2[i])){
                m2[line2[i]]++;
            }
            else{
                m2.insert(make_pair(line2[i], 1));
            }
        }
        for(int i=0; i<length3; i++){
            if(m3.count(line3[i])){
                m3[line3[i]]++;
            }
            else{
                m3.insert(make_pair(line3[i], 1));
            }
        }
        for(const auto &[key1, val1] : m1){
            for(const auto &[key2, val2] : m2){
                for(const auto &[key3, val3] : m3){
                    if(key1 == key2 && key1 == key3 && key2 == key3){
                        if(islower(key1)){
                            output += key1 - 'a' + 1;
                        }
                        else{
                            output += key1 - 'A' + 27;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << "Ans= " << output << '\n';
    fin.close();
}
