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

int main() {
  ll N,L,T;
  cin>>N>>L>>T;
  vector<ll> l,r;
  ll s;
  rep(i,N){
    ll X,W;
    cin>>X>>W;
    if(i==0) s = W;
    if(W==1LL) r.push_back(X);
    if(W==2LL) l.push_back(X);
  }
  vector<ll> last;
  for(auto x:r){
    last.push_back((x+T)%L);
  }
  for(auto x:l){
    ll p = (x-T)%L;
    if(p<0) p+=L;
    last.push_back(p);
  }
  sort(last.begin(),last.end());
  vector<ll> ans(N);
  if(s==1){
    ll c = (T*2LL)/L,d=(T*2LL)%L;
    ll total = c*(ll)l.size();
    total += (ll)(upper_bound(l.begin(),l.end(),(r[0]+d)%L)-l.begin());
    total %= N;
    ll u = lower_bound(last.begin(),last.end(),(r[0]+T)%L)-last.begin();
    if(u!=N-1&&last[u]==last[u+1]) u++;
    rep(i,N){
      ans[(total+i)%N] = last[(u+i)%N]; 
    }
  }
  else{
    ll c = (T*2LL)/L,d=(T*2LL)%L;
    ll total = c*(ll)r.size();
    ll q = (l[0]-d)%L;
    q+=L;
    total += (ll)(r.end()-lower_bound(r.begin(),r.end(),q));
    total %= N;
    q=(l[0]-T)%L;
    if(q<0) q+=L;
    ll u = lower_bound(last.begin(),last.end(),q)-last.begin();
    rep(i,N){
      ans[i] = last[(u+total+i)%N]; 
    }
  }
  for(auto x:ans) {
    printf("%lld\n",x);
  }
}