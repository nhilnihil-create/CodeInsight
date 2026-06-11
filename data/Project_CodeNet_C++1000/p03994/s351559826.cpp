#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    ll K;
    cin >> K;
    // string alphabet ="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<S.size();i++){
        int t= S[i] -'a';
        // cerr <<"t=" <<t  <<"K=" <<K<< endl;
        if(i == S.size()-1){
            S[i] = 'a' +(t+K)%26;
            K=0;
            break;
        }
        if(t==0){
            continue;
        }
        if(26-t<=K){
            S[i] = 'a';
            K-= (26-t);
        }
    }
    cout << S << endl;

    return 0;
}