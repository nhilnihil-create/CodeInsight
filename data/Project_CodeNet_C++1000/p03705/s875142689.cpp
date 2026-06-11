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
map<char, int> m;
signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a==b && n==1) cout << 1 << endl;
    else if(n<2) cout << 0 << endl;
    else if(a>b) cout << 0 << endl;
    else {
        cout << b*(n-1)+a - (a*(n-1)+b) + 1 << endl;
    }
  return 0;
}

