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
  ll a, b, n, t, u, s;
  in(n);
  vector<ll> c(n), e(n);
  rep(i, n)
    in(c[i]);
  sort(all(c));
  s = 1;
  vector<bool> d(n, false);
  d[n - 1] = true;
  a = n - 2;
  e[0] = c[0];
  rep(i, n - 1)
    e[i + 1] = c[i + 1] + e[i];
  rep(i, n - 1){
    if(e[n - 2 - i] * 2 >= c[n - i - 1])
      s++;
    else
      break;
  }
  out(s);
  memi;
}
