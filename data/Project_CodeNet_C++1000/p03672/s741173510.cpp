#include<bits/stdc++.h>
using namespace std;

string S;

bool odd_string(string S, int i){
    if((S.size() - i) % 2 == 1) return false;
    for(int j = 0; j < (S.size()-i)/2; ++j){
        if(S[j] != S[j+(S.size()-i)/2]) return false;
    }
    return true;
}

int main(){
    cin >> S;
    int i = 1;
    while(!odd_string(S, i)){
        ++i;
    }
    cout << S.size() - i << endl;
    return 0;
}