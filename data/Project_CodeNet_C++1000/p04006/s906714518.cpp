#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()

int main(){
  ll N, x; cin >> N >> x;
  vector<ll> a(N);
  vector<vector<ll>> b(N, vector<ll>(N));
  REP(i, N) {
    cin >> a[i];
    b[i][0] = a[i];
  }
  ll ans = 1e18;
  //魔法の回数kで全探索
  REP(k,N){
    ll cost = k*x;
    REP(i,N){
      if(k!=0) b[i][k] = min(b[i][k-1], a[(i-k+N)%N]);
      cost += b[i][k];
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}

