#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    string S;
    cin >> S;
    ll cnt = 0;
    for(int i = 0; i < S.size() - 1; i++){
        if(S[i] != S[i + 1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}   
