#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

signed main(){
    string s;
    cin >> s;
    int ans = 0;
    char c = s[0];
    rep(i,s.length()) {
        if(i==0) continue;
        if(s[i] != c) ans++;
        c = s[i];
    }
    cout << ans << endl;

    return 0;
}