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
  ll N, M; cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  REP(i,N) REP(j,M){
    cin >> A[i][j];
    A[i][j]--;
  }
  vector<ll> p(N,0);
  vector<bool> use(M,true);
  ll ans = N;
  
  REP(j,M-1){
    vector<ll> cnt(M,0);
    REP(i,N){
      while(!use[A[i][p[i]]]) p[i]++;
      cnt[A[i][p[i]]]++;
    }
    ll tmp = 0, idx = -1;
    REP(i,M){
      if(tmp < cnt[i]){
        tmp = cnt[i];
        idx = i;
      }
    }
    ans = min(ans,tmp);
    use[idx] = false;
  }
  cout << ans << endl;
}