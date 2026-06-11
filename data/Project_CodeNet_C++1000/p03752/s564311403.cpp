#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

int next_combination(int sub) {//組み合わせ全列挙に使うやつ
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  ll bit = (1<<K) -1;
  ll ans = INF;
  for(;bit<(1<<N);bit=next_combination(bit)){
    ll h = 0;
    ll cnt = 0;
    for(ll i = 0; i < N; i++){
      if(bit&(1<<i)) {
        if(h>=v[i]) {
          cnt+=h-v[i]+1;
          h++;
        }
        else chmax(h,v[i]);
      }
      else chmax(h,v[i]);
    }
    chmin(ans,cnt);
  }
  cout<<ans<<endl;
}