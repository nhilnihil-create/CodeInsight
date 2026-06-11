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

  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n), b(n);
  rep(i, n){
    cin >> a[i] >> b[i];
  }

  ll mask = (1LL<<32) - 1LL;

  ll ans = 0;
  for(int i = 0; i < 31; i++){
    if(k & (1LL<<i)){

      ll tans = 0;
      ll num = k & (mask << i);

      for(int j = 0; j < n; j++){
        ll numa = a[j] & (mask << i);
        if((num | numa) == num && (a[j] & (1<<i)) == 0LL){
          tans += b[j];
        }
      }
      chmax(ans, tans);
    }
  }

  ll tans = 0;
  rep(j, n){
    if((k | a[j]) == k){
      tans += b[j];
    }
  }
  chmax(ans, tans);

  cout << ans << endl;
  
  return 0;
}
