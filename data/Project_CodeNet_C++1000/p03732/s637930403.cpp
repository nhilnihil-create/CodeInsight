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
  ll n, w, a, b, c;
  in2(n, w);
  vector<ll> p, q, r, s, pp, qq, rr, ss;
  in2(a, b);
  p.pb(b);
  c = a;
  rep(i, n - 1){
    in2(a, b);
    if(a == c)
      p.pb(b);
    if(a - 1 == c)
      q.pb(b);
    if(a - 2 == c)
      r.pb(b);
    if(a - 3 == c)
      s.pb(b);
  }
  sort(all(p));
  sort(all(q));
  sort(all(r));
  sort(all(s));
  reverse(all(p));
  reverse(all(q));
  reverse(all(r));
  reverse(all(s));
  pp.pb(0);
  qq.pb(0);
  rr.pb(0);
  ss.pb(0);
  rep(i, p.size())
    pp.pb(p[i] + pp[i]);
  rep(i, q.size())
    qq.pb(q[i] + qq[i]);
  rep(i, r.size())
    rr.pb(r[i] + rr[i]);
  rep(i, s.size())
    ss.pb(s[i] + ss[i]);
  a = 0;
  rep(i, pp.size()){
    rep(j, qq.size()){
      rep(k, rr.size()){
        rep(l, ss.size()){
          b = c * i + (c + 1) * j + (c + 2) * k + (c + 3) * l;
          if(b <= w)
            a = max(a, pp[i] + qq[j] + rr[k] + ss[l]);
        }
      }
    }
  }
  out(a);
  memi;
}
