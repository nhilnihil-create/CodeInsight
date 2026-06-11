#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

  ll I, O, T, J, L, S, Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;

  ll ans = 0;
  ans += O;

  ans += 2 * (I / 2);
  ans += 2 * (J / 2);
  ans += 2 * (L / 2);

  if(I % 2 == 1 && J % 2 == 1 && L % 2 == 1){
    ans += 3;
  }else if(I % 2 == 1 && J % 2 == 1 && L >= 2){
    ans += 1;
  }else if(I % 2 == 1 && J >= 2 && L % 2 == 1){
    ans += 1;
  }else if(I >= 2 && J % 2 == 1 && L % 2 == 1){
    ans += 1;
  }

  cout << ans << endl;


  return 0;
}
