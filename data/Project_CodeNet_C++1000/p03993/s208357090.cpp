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
    cin>>n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    rep(i,n){
        if(i==a[a[i]])ans++;
    }
    cout << ans/2 << endl;
    return 0;

}

