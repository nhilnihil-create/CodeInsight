#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll a, b, n, k;
  string s = "IMPOSSIBLE";
  in2(n, k);
  vector<ll> c(n);
  rep(i, n){
    in(c[i]);
    if(c[i] == k)
      s = "POSSIBLE";
  }
  a = c[0];
  b = 0;
  rep(i, n){
    a = __gcd(a, c[i]);
    b = max(b, c[i]);
  }
  if(k % a == 0 && b >= k)
    s = "POSSIBLE";
  out(s);
  memi;
}