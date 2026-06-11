#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

//すべて半閉区間で扱う
struct cBIT {
  vector<ll> v;
  ll n;
  cBIT(ll n) : n(n), v(n) {}
  void add(ll i, ll x) {
    i++;
    while (i <= n) {
      v[i - 1] += x;
      i += i & -i;
    }
  }
  ll sum(ll i) {
    ll r = 0;
    while (i >= 1) {
      r += v[i - 1];
      i -= i & -i;
    }
    return r;
  }
  ll sum(ll l, ll r){
    if(l>=r)return 0;
    return sum(r)-sum(l);
  }
  ll get(ll i){return sum(i+1)-sum(i);}
};
 
struct BIT {
  cBIT p, q;
  BIT(ll n) : p(n + 1), q(n + 1) {}
  void add(ll l, ll r, ll w) {
    p.add(l, -w * l);
    p.add(r, w * r);
    q.add(l, w);
    q.add(r, -w);
  }
  ll sum(ll r) {
    return p.sum(r) + q.sum(r) * r;
  }
  ll sum(ll l, ll r){
    if(l>=r)return 0;
    return sum(r)-sum(l);
  }
  ll get(ll i){return sum(i+1)-sum(i);}
};
//↑すべて半閉区間で扱う

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> a(N+1,0);
    for(ll i=0;i<N;++i)cin>>a[i+1];
    vector<ll> sum(N+1,0);
    for(ll i=1;i<=N;++i)sum[i]=sum[i-1]+a[i];
    vector<P> vec(N+1);
    for(ll i=0;i<N+1;++i)vec[i]=P(i*K-sum[i],-i);
    ll ans=0;
    sort(vec.begin(), vec.end());
    BIT tree(N+1);
    for(ll i=0;i<N+1;++i){
        ans+=tree.get(-vec[i].second+1);
        tree.add(0,-vec[i].second+1,1);
    }
    prt(ans)fl

    
    return 0;
}
