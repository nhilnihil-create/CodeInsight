// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
template <typename Monoid >
struct SegmentTree{
  using F = function< Monoid(Monoid,Monoid) >;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M;

  SegmentTree(int n,const F f,const Monoid &M) : f(f),M(M){
    sz = 1;
    while(sz<n) sz<<=1;
    seg.assign(sz*2,M);
  }
  void set(int k,const Monoid &v){
    seg[k+sz] = v;
  }
  void build(){
    for(int k=sz-1;k>0;k--){
      seg[k] = f(seg[2*k],seg[2*k+1]);
    }
  }
  void update(int k,const Monoid &v){
    k += sz;
    seg[k] = v;
    while(k >>= 1){
      seg[k] = f(seg[2*k],seg[2*k+1]);
    }
  }
  Monoid que(int a,int b){
    Monoid L=M,R=M;
    for(a+=sz, b+=sz;a<b;a>>=1,b>>=1){
      if(a&1) L = f(L,seg[a++]);
      if(b&1) R = f(seg[--b],R);
    }
    return f(L,R);
  }
  Monoid operator[](const int &k) const{
    return seg[k+sz];
  }
};
signed main(){
  init_io();
  ll n,k,ans=0;
  cin >> n >> k;
  vector<ll> a(n),sum(n+1,0);
  SegmentTree<ll> seg(n+2,[](ll a,ll b){return a+b;},0);
  priority_queue<P> que;
  multiset<P> st;
  map<ll,ll> mp;
  const ll MAX = 1e18;
  st.insert(P(MAX,n+1));
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum[i+1] = sum[i] + (a[i]-k);
    que.push(P(sum[i+1],i+1));
  }
  que.push(P(0,0));
  for(int i=0;i<=n;i++){
    auto tmp = que.top(); que.pop();
    mp[tmp.second] = i;
    if(tmp.second==0){
      seg.update(i,1);
      st.insert(P(0,i));
    }
  }
  for(int i=0;i<n;i++){
    auto itr =st.lower_bound(P(-sum[i+1],-MAX));
    ll idx = itr->second;
    ans += seg.que(idx,n+1);
    /*
    cout << idx <<" "<<itr->first <<" "<<itr->second<<endl;
    for(int i=0;i<n+2;i++){
      cout << seg[i]<<" ";
    }
    cout << endl;
    */
    st.insert(P(-sum[i+1],mp[i+1]));
    seg.update(mp[i+1],1);
  }
  cout << ans << endl;
}
