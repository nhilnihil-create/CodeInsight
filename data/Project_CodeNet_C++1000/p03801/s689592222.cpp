#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct BIT{
  ll bit[1000010];
  void add(ll a,ll w){
    for(ll x = a; x < 1000010; x+=(x&-x)) bit[x]+=w;
  }
  ll sum(ll a){
    ll ret = 0LL;
    for ( ll x = a; x > 0;x-=(x&-x)) ret += bit[x];
    return ret;
  }
};


int main(){
  ll N;
  cin>>N;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  vector<ll> ans(N,0);
  BIT B;
  vector<P> vp(N);
  rep(i,N) {
    vp[i].first=v[i];
    vp[i].second=i;
  }
  sort(vp.begin(),vp.end(),[](P a,P b){
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
  });
  vector<ll> S(N);
  BIT cn;
  rep(i,N){
    S[vp[i].second] = B.sum(N) - B.sum(vp[i].second)-(cn.sum(N)-cn.sum(vp[i].second))*vp[i].first;
    B.add(vp[i].second+1,vp[i].first);
    cn.add(vp[i].second+1,1);
  };
  vector<ll> C(N);
  ll c = 0;
  rep(i,N){
    if(chmax(c,v[i])) C[i] = i;
    else C[i] = C[i-1];
  }
  ll all = 0;
  rep(i,N) all += v[i];
  ll cnt = 0;
  rep(i,N){
    if(vp[i].second==0){
      ans[0] = all - cnt;
      break;
    }
    if(C[vp[i].second]==C[vp[i].second-1]) {
      ans[vp[i].second] = 0;
      continue;
    }
    ans[vp[i].second] = S[C[vp[i].second-1]]-cnt;
    cnt += ans[vp[i].second];
  }
  rep(i,N) cout<<ans[i]<<endl;
}