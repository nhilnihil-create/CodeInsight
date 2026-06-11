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
  map<ll,ll> m;
  for(ll i = 0; i < M; i++){
    ll x,y;
    cin>>x>>y;
    m[x]++;
    m[y]++;
  }
  bool can = true;
  for(auto x:m) {
    if(x.second%2!=0) can = false;
  }
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}