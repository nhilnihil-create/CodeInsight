#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll gcd(ll x, ll y) {
    if (x % y == 0LL) {
        return y;
    }

    else {
        return gcd(y, x % y);
    }
}

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  ll t = v[0];
  for(ll i = 1; i < N; i++) t=gcd(t,v[i]);
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  if(K<=v[0]&&(K-v[0])%t==0) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}