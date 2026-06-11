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
  ll t = 2;
  ll ans = 0;
  for(ll i = 0; i < N; i++){
    if(i==0) ans+=v[i]-1;
    else{
      ans+=(v[i]-1)/t;
      if(v[i]==t) t++;
    }
  }
  cout<<ans<<endl;
}