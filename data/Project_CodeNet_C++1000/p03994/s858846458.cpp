#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//a = 97, z = 122

int ascii(char ch){
    int x = ch;
    return 123-x;
}

int main() {
    string S; cin >> S;
    int K; cin >> K;
    for(int i = 0; i < S.size(); i++){
        int x = ascii(S[i]);
        //cout << " " << S[i] << " " << x <<" " <<  K << endl;
        if(S[i] == 'a') continue;
        if(x <= K) {
            S[i] = 'a';
            K-=x;
            
        }
        else continue;
    }
    if(K != 0){
        int las = S[S.size()-1];
        las += K%26;
        S[S.size()-1] = las; 
    }
    cout << S << endl;
}