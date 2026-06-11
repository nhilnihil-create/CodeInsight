#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s[3];
    rep(i, 0, 3) cin >> s[i];
    queue<ll> que[3];
    rep(i, 0, 3){
        for(auto e : s[i]) que[i].push(e);
    }
    ll i = 0;
    while(true){
        cerr << i << endl;
        if(que[i].empty()){
            cout << (char)('A'+i) << endl;
            break;
        }
        ll j = que[i].front();
        que[i].pop();
        i = j-'a';
    }
    return 0;
}