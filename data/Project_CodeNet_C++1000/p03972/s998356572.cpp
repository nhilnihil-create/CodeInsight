#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int W, H;
  cin >> W >> H;

  vector<pair<ll, ll>> p;

  rep(i, W){
    ll tmp;
    cin >> tmp;
    p.emplace_back(tmp, 0LL);
  }

  rep(i, H){
    ll tmp;
    cin >> tmp;
    p.emplace_back(tmp, 1);
  }

  int cnt_w = 0;
  int cnt_h = 0;

  sort(p.begin(), p.end());

  ll ans = 0;
  ll num_e = 0;
  rep(i, W+H){

    auto q = p[i];

    if(q.second==0){
      
      ans += q.first * (H-cnt_h+1);
      cnt_w++;
      num_e += (H-cnt_h+1);

    }else{

      ans += q.first * (W-cnt_w+1);
      cnt_h++;
      num_e += (W-cnt_w+1);
    }
  }

  cout << ans << endl;


  return 0;
}
