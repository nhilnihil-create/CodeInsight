#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    map<char,int>Map;
    for(int i = 0; i < S.size(); i++) {
        Map[S[i]]++;
    }
    for(int i = 0; i < S.size(); i++) {
        if(Map[S[i]] > 1) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}

