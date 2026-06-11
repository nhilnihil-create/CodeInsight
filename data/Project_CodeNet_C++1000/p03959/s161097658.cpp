#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<ll> T(N),A(N);
  rep(i,N) cin>>T[i];
  rep(i,N) cin>>A[i];
  reverse(A.begin(),A.end());
  vector<ll> hi(N);
  hi[0] = T[0];
  hi[N-1] = A[0];
  vector<bool> ok(N);
  bool can = true;
  ok[0] = ok[N-1] = true;
  if(T[0]>A[N-1]||A[0]>T[N-1]) can = false;
  for(int i = 1; i < N; i++){
    if(T[i-1]!=T[i]){
      ok[i] = true;
      hi[i] = T[i];
      if(T[i]>A[N-i-1]) can = false;
    }
    else hi[i] = T[i];
  }
  for(int i = 1; i < N; i++){
    if(A[i-1]!=A[i]){
      if(ok[N-i-1]&&hi[N-i-1]!=A[i]) can = false;
      if(A[i]>T[N-i-1]) can = false;
      ok[N-i-1] = true;
      hi[N-i-1] = A[i];
    }
    else chmin(hi[N-i-1],A[i]);
  }
  if(!can) cout<<0<<endl;
  else {
    ll ans = 1;
    rep(i,N){
      if(!ok[i]) ans = (ans * hi[i])%mod;
    }
    cout<<ans<<endl;
  }
}