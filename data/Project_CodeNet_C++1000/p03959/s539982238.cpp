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
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  for(ll i = 0LL; i < N;i ++) cin>>A[i];
  for(ll i = 0LL; i < N;i ++) cin>>B[i];
  unordered_map<ll,bool> m;
  vector<ll> hi(N);
  for(ll i = 0LL; i < N; i++){
    hi[i]=A[i];
    if(i==0){
      m[i]=true;
    }
    if(i!=0){
      if(A[i]!=A[i-1]) m[i]=true;
    }
  }
  bool can = true;
  for(ll i = N-1; i >= 0; i--){
    if(i==N-1){
      if(m[i]&&hi[i]!=B[i]){
        can = false;
        break;
      }
      if(B[i]>hi[i]){
        can = false;
        break;
      }
      m[i]=true;
    }
    if(i!=N-1){
      if(B[i]!=B[i+1]){
        if(m[i]&&hi[i]!=B[i]){
          can = false;
          break;
        }
        if(B[i]>hi[i]){
          can = false;
          break;
        }
        m[i]=true;
      }
    }
    chmin(hi[i],B[i]);
  }
  ll ans = 1LL;
  if(can){
    for(ll i = 0LL; i < N; i++){
      if(m[i]) continue;
      ans=(ans*hi[i])%mod;
    }
    cout<<ans<<endl;
  }
  else {
    cout<<0<<endl;
  }
}