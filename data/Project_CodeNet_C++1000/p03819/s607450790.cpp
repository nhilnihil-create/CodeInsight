#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define US unordered_set
#define ALL(a) (a).begin(),(a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vvi> vvvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;
const ll MOD = 1000000007;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

struct RAQ{
  ll size;
  ll *tree;
  RAQ(ll sz){
    ll logsize; for(logsize=0;(1ll<<logsize)<=sz;logsize++);
    size=(1ll<<logsize);
    tree=new ll[size*2-1]; REP(i,size*2-1) tree[i]=0;
  }
  void add(ll s,ll t,ll x){
    add(s,t,0,size,x,0);
  }
  void add(ll s,ll t,ll l,ll r,ll x,ll k){
    if(r<=s||t<=l||r<=l) return;
    if(l+1==r) {tree[k]+=x; return;}
    if(s<=l&&r<=t) {tree[k]+=x; return;}
    ll mid=(l+r+1)/2;
    add(s,t,l,mid,x,k*2+1);
    add(s,t,mid,r,x,k*2+2);
  }
  ll get(ll i){
    ll k=i+size-1;
    ll ret=tree[k];
    while(k){
      k=(k-1)/2;
      ret+=tree[k];
    }
    return ret;
  }
};


int main() {
  ll N,M; cin>>N>>M;
  RAQ raq(M+1);
  vi l(N),r(N); REP(i,N) cin>>l[i]>>r[i];
  vvpii v(M+1);
  REP(i,N) {
    v[r[i]-l[i]+1].PB({l[i],r[i]});
  }
  ll cnt=N;
  FOR(d,1,M+1) {
    for(pii p:v[d-1]) raq.add(p.first,p.second+1,1);
    cnt-=v[d-1].size();
    ll ans=cnt;
    for(ll i=0;i*d<=M;i++) ans+=raq.get(i*d);
    cout<<ans<<endl;
  }
}
