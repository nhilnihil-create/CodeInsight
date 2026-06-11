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
  in(n);
  vector<ll> c(n), d(n);
  rep(i, n){
    in2(c[i], d[i]);
  }
  a = c[0];
  b = d[0];
  rep(i, n - 1){
    if(c[i + 1] == c[i] && d[i + 1] == d[i])
      continue;
    if(a % c[i + 1] != 0)
      a = a + c[i + 1] - (a % c[i + 1]);
    k = (a / c[i + 1]) * d[i + 1];
    if(k >= b)
      b = k;
    else{
      if(b % d[i + 1] != 0)
        b = b + d[i + 1] - (b % d[i + 1]);
      a = (b / d[i + 1]) * c[i + 1];
    }
  }
  out(a + b);
  memi;
}
