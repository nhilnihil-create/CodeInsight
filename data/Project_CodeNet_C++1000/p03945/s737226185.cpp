#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    string s; cin >> s;
    char t = s[0];
    ll ans = 0;
    rep(i, s.length()){
        if(s[i] != t){
            t = s[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}