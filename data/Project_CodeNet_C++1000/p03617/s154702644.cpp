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
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    int q,h,s,d;
    cin >> q >> h >> s>> d;
    int n;
    cin >> n;
    int qq = 8*q;
    int hh = 4*h;
    int ss = 2*s;
    int mi = min(qq,min(hh,min(ss,d)));
    int ans = n/2*mi;
    if(n%2==1) {
        qq = 4*q;
        hh = 2*h;
        mi = min(qq,min(hh,s));
        ans += mi;
    }
    cout << ans << endl;
    return 0;
}

