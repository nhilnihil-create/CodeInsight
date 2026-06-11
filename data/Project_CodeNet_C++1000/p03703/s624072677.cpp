#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<lb,lb>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct BIT{
  int bit[1000010];
  void add(int a,int w){
    for(int x = a; x < 1000010; x+=(x&-x)) bit[x]+=w;
  }
  int sum(int a){
    int ret = 0;
    for ( int x = a; x > 0;x-=(x&-x)) ret += bit[x];
    return ret;
  }
};

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  rep(i,N) v[i] -= K;
  vector<ll> w(N+1,0);
  rep(i,N){
    if(i==0) w[i+1]=v[i];
    else w[i+1] = w[i]+v[i];
  }
  ll ans = 0;
  vector<ll> s = w;
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  rep(i,N+1){
    ll t = lower_bound(s.begin(),s.end(),w[i])-s.begin()+1;
    w[i] = t;
  }
  BIT B;
  rep(i,N+1){
    ans += B.sum(w[i]);
    B.add(w[i],1);
  }
  cout<<ans<<endl;
}