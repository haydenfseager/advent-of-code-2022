#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>


//The length will always be an even number

using namespace std;

map<char, int> m1, m2;

int main(){
    int output = 0, length;
    string input;
    ifstream fin;
    fin.open("day3.txt");
    while(getline(fin, input)){
        length = input.length()-1;
        m1.clear();
        m2.clear();
        for(int i=0; i<length; i++){
            if(i<length/2){
                if(m1.count(input[i])){
                    m1[input[i]]++;
                }
                else{
                    m1.insert(make_pair(input[i], 1));
                }
            }
            else{
                if(m2.count(input[i])){
                    m2[input[i]]++;
                }
                else{
                    m2.insert(make_pair(input[i], 1));
                }
            }
        }
        for(const auto &[key1, val1] : m1){
            for(const auto &[key2, val2] : m2){
                if(key1 == key2){
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
    cout << "Ans= " << output << '\n';
    fin.close();
}
