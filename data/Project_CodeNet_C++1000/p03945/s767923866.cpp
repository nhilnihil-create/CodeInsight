#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;

    ll cnt = 0;

    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i+1]) cnt++;
    }
    //if(cnt > 1) cnt++;
    put(cnt);
}