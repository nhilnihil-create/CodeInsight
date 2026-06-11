#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(void)
{
  LL n,m;
  LL p = 1000000007ll;
  cin >> n >> m;
  vector<LL> x(n),y(m);
  for(LL &xi:x) cin >> xi;
  for(LL &yi:y) cin >> yi;
  LL w=0ll,h=0ll;
  REP(i,n-1) {
    w=(w+(x[i+1]-x[i])*(i+1)*(n-i-1))%p;
  }
  REP(i,m-1) {
    h=(h+(y[i+1]-y[i])*(i+1)*(m-i-1))%p;
  }
  cout << w*h%p << endl;
}
