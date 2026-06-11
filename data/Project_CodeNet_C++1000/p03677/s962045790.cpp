#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N,M;
  cin>>N>>M;
  vector<ll> v(N);
  for(ll i = 0LL; i < N; i++){
    ll x;
    cin>>x;
    v[i]=x-1LL;
  }
  ll ans = 0LL;
  vector<ll> B(M*2LL,0LL);
  for(ll i = 0; i < N-1LL; i++){
    if(v[i]<v[i+1]) {
      ans+=v[i+1]-v[i];
      if(v[i+1]-v[i]<2LL) continue;
      B[v[i]+2]++;
      B[v[i+1]+1]--;
    }
    if(v[i]>v[i+1]){
      ans+=v[i+1]+M-v[i];
      if(v[i+1]+M-v[i]<2LL) continue;
      B[v[i]+2LL]++;
      B[v[i+1]+M+1]--;
    }
  }
  for(ll i = 1LL; i < M*2LL; i++){
    B[i]=B[i-1]+B[i];
  }
  for(ll i = 0; i < N-1LL; i++){
    if(v[i]<v[i+1]) {
      if(v[i+1]-v[i]<2LL) continue;
      B[v[i+1]+1]-=v[i+1]-v[i]-1;
    }
    if(v[i]>v[i+1]){
      if(v[i+1]+M-v[i]<2LL) continue;
      B[v[i+1]+M+1]-=v[i+1]+M-v[i]-1;
    }
  }
  for(ll i = 1LL; i<M*2LL; i++){
    B[i]=B[i-1]+B[i];
  }
  vector<ll> A(M);
  for(ll i = 0LL; i < M;i++){
    A[i]=B[i]+B[i+M];
  }
  ll t = 0LL;
  for(auto x:A) {
    chmax(t,x);
  }
  ans-=t;
  cout<<ans<<endl;
}