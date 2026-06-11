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
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  map<ll,ll> m;
  for(ll i = 0; i < N; i++) m[v[i]]=i;
  sort(v.begin(),v.end());
  ll cnt = 0LL;
  for(ll i = 0; i < N; i++){
    ll t = i-m[v[i]];
    if(t%2LL!=0) cnt++;
  }
  cout<<cnt/2<<endl;
}