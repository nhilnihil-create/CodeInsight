#include <iostream>

using namespace std;
using ll = long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<"\n"
const ll INF = 1LL << 60;
const int MAX_N = 2e5;

ll sum[MAX_N + 1];
int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  IN(N);

  REP(i, N) {
    IN(a);
    sum[i+1] = (ll)sum[i] + a;
  }
  ll ans = INF;
  FOR(i, 1, N) {
    ll x = sum[i];
    ll y = sum[N] - sum[i];
    ans = min(ans, abs(x - y));
  }
  OUT(ans);

  return 0;
}
