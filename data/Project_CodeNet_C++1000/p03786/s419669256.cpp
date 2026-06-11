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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n+1,0);
    rep(i,n) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    rep(i,n) {
        b[i+1] = a[i]+b[i];
    }
    int ans = 1;
    rrep(i,n) {
        if(b[i]*2>=a[i]) ans++;
        else break;
        //cout << b[i]<<" "<<a[i]<<" "<<i << endl;
    }
    cout << ans << endl;

    
  return 0;
}

