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
  ll N,L;
  cin>>N>>L;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  bool can = false;
  ll t;
  for(ll i = 0; i < N-1; i++){
    if(v[i]+v[i+1]>=L) {
      t=i;
      can = true;
      break;
    }
  }
  if(can) {
    cout<<"Possible"<<endl;
    for(ll i = 0; i < t; i++){
      cout<<i+1LL<<endl;
    }
    for(ll i = N-2; i>t;i--){
      cout<<i+1LL<<endl;
    }
    cout<<t+1LL<<endl;
  }
  if(!can)  cout<<"Impossible"<<endl;
}