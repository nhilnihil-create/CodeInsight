#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<queue>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;

ll n,m,x[100010], y[100010];

void compute() {
  ll sumX = 0;
  REP(i,1,n+1) {
    ll v1 = ( x[i] * (ll)(i-1) ) % mod;
    ll v2 = ( x[i] * (ll)(n-i) ) % mod;
    ll v  = ( v1 - v2 ) % mod;
    ( sumX += v ) %= mod;
  }
  ll sumY = 0;
  REP(i,1,m+1) {
    ll v1 = ( y[i] * (ll)(i-1) ) % mod;
    ll v2 = ( y[i] * (ll)(m-i) ) % mod;
    ll v  = ( v1 - v2 ) % mod;
    ( sumY += v ) %= mod;
  }
  ll ans = ( sumX * sumY ) % mod;
  while( ans < 0LL ) ans += mod;
  cout << ans % mod << endl;
}

int main() {
  cin >> n >> m;
  REP(i,1,n+1) cin >> x[i];
  REP(i,1,m+1) cin >> y[i];
  compute();
  return 0;
}