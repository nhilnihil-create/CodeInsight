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
#define SZ(x) ll(x.size())

int main(){
  ll N,K; cin >> N >> K;
  vector<ll> a(N), b(N);
  REP(i,N){
    cin >> a[i];
    b[i] = max(0LL, a[i]);
  }
  vector<ll> suma(N+1,0), sumb(N+1,0);
  REP(i,N){
    suma[i+1] = suma[i] + a[i];
    sumb[i+1] = sumb[i] + b[i];
  }

  ll ans = -1e18;
  //i,i+1,...,i+K-1の色を固定
  FOR(i,1,N-K+2){
    ll u = max(0LL,suma[i+K-1]-suma[i-1]);
    ll t = sumb[i-1] + u + sumb[N] - sumb[i+K-1];
    ans = max(ans,t);
  }
  cout << ans << endl;
}