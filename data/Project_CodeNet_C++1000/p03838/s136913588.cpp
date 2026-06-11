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

  ll x, y;
  cin >> x >> y;

  if(x >= 0){

    if(y >= x){
      cout << y - x << endl;
      return 0;
    }

    if(y > 0){
      cout << 2 + (x-y) << endl;
      return 0;
    }

    cout << 1 + abs(x - abs(y)) << endl;

  }else{

    if(y < x){
      cout << 2 + abs(y-x) << endl;
      return 0;
    }

    if(y <= 0){
      cout << abs(y-x) << endl;
      return 0;
    }

    cout << 1 + abs(abs(y)-abs(x)) << endl;


  }




  return 0;
}
