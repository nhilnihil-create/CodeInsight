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

const ll M = 1e9+7;
void no(){
  cout << 0 << endl;
  exit(0);
}

int main(){
  ll N; cin >> N;
  vector<ll> T(N+2,0), A(N+2,0);
  ll bound; // H[bound]でmax
  ll maxi = 0;
  REP(i, N){
    cin >> T[i+1];
    if(T[i+1]>T[i]){
      bound = i+1;
      maxi = T[i+1];
    }
  }
  T[N+1] = maxi;
  A[0] = maxi;
  REP(i, N) cin >> A[i+1];
  REP(i,bound+1){
    if(A[i] != maxi) no();
  }
  
  ll ans = 1;
  FOR(i,1,bound){
    if(T[i]>T[i-1]) continue;
    (ans *= T[i]) %= M;
  }
  IFOR(i,bound+1,N+1){
    if(A[i]>A[i+1]) continue;
    (ans *= A[i]) %= M;
  }
  cout << ans << endl;
}