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
    vector<int> a(3);
    rep(i,3)cin >> a[i];
    sort(a.begin(),a.end());
    int aa = a[2]-(a[2]+1)/2;
    int bb = a[2]-a[2]/2;
    //cout << aa-bb << endl;
    cout << abs(a[0]*a[1]*(aa-bb)) << endl;
}

