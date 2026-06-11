#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    string S;
    cin >> S;
    int K;
    cin >> K;
    rep(i,S.size()){
        if(S[i] == 'a') continue;
        if('z' - S[i] + 1 <= K){
            K -= 'z' - S[i] + 1;
            S[i] = 'a';
        }
    }
    if(K > 0) K %= 26;
    rep(i,K){
        S[S.size()-1] = S[S.size()-1] + 1;
        if(S[S.size()-1] == 'z' + 1) S[S.size()-1] = 'a';
    }
    cout << S << endl;

    return 0;
}