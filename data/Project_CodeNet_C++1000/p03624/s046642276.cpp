#include <bits/stdc++.h>
using namespace std;

string S;

int main(){

    cin >> S;
    char buf = 'a';
    int size = S.size();
    map<char, int> dict;

    for (int i=0; i<size; i++){
        dict[S.at(i)]++;
    }

    int cnt = 0;
    for (auto p: dict){
        auto key = p.first;
        auto value = p.second;

        if (key == buf){
            buf++;
            cnt++;
        }
    }

    if (cnt < 26){
        cout << buf << endl;
    }
    else{
        cout << "None" << endl;
    }
}