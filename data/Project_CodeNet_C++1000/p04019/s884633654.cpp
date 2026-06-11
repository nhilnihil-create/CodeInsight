#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    string S;
    cin >> S;
    int n = 0;
    int w = 0;
    int s = 0;
    int e = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'N') n++;
        else if(S[i] == 'W') w++;
        else if(S[i] == 'S') s++;
        else e++;
    }
    if(n != 0){
        if(s == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(w != 0){
        if(e == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(s != 0){
        if(n == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(e != 0){
        if(w == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}