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
  ll h, w, a, b, c, s;
  in2(h, w);
  s = min(h, w);
  if(h % 3 == 0 || w % 3 == 0)
    s = 0;
  rep(i, h + 1){
    rep(j, 1000){
      a = i * w;
      b = (h - i) * (w / 2 - j);
      c = (h - i) * (w - w / 2 + j);
      s = min(s, max({a, b, c}) - min({a, b, c}));
    }
  }
  rep(i, w + 1){
    rep(j, 1000){
      a = i * h;
      b = (w - i) * (h / 2 - j);
      c = (w - i) * (h - h / 2 + j);
      s = min(s, max({a, b, c}) - min({a, b, c}));
    }
  }
  out(s);
  memi;
}