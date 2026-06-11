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
  ll a, b, c, d, e, f, s, t, u, v;
  double x, y;
  x = 0;
  v = 0;
  in3(a, b, c);
  in3(d, e, f);
  u = 100 * a;
  rep(i, f / (100 * a) + 1){
    rep(j, f / (100 * b) + 1){
      s = i * 100 * a + j * 100 * b;
      if(s == 0)
        continue;
      if(s > f)
        continue;
      rep(k, (s / 100 * e) / c + 1){
        rep(l, (s / 100 * e) / d + 1){
          t = k * c + l * d;
          if(s + t > f)
            continue;
          if(100 * t > s * e)
            continue;
          y = (double)t / (double)(s + t);
          if(x < y){
            x = y;
            u = s + t;
            v = t;
          }
        }
      }
    }
  }
  out(u);
  hina;
  out(v);
  memi;
}
