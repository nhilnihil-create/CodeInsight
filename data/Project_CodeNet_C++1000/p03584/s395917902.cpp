#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N),B(N);
  rep(i,N) cin>>A[i]>>B[i];
  ll ans = 0;
  rep(i,N){
    if((K|A[i])==K) ans += B[i];
  }
  for(int i = 31; i>=0; i--){
    ll t = 0;
    if(K&(1LL<<i)){
      ll p = (K|((1LL<<i)-1))-(1LL<<i);
      rep(i,N) {
        if((p|A[i])==p) t+=B[i]; 
      }
    }
    chmax(ans,t);
  }
  cout<<ans<<endl;
}