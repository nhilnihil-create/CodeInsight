#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

map<ll, ll> prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    map<ll,ll> ans;
    for(ll i=2;i<=N;++i){
        map<ll,ll> M=prime_factor(i);
        for(auto p: M){ans[p.first]+=p.second;ans[p.first]%=MOD;}
    }
    ll ret=1;
    for(auto p: ans){ret*=p.second+1;ret%=MOD;}
    prt(ret)
    return 0;
}
