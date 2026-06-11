#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    string S;
    cin >> S;
    int N = S.length();
    S += "..";
    rep(i,N){
        if(S[i] == S[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        } else if(S[i] == S[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;

    return 0;
}