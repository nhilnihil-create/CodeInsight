#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll comb(int n, int r) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v[n][r];
}

int main()
{
    int n, p;
    cin >> n >> p;
    int e = 0;
    int o = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(a % 2) ++o;
        else ++e;
    }
    if(o == 0 && p == 1) {
        cout << 0 << endl;
        return 0;
    }
    else if(o == 0 && p == 0) {
        ll l = 1;
        rep(i, n) {
            l *= 2;
        }
        cout << l << endl; 
        return 0;
    }
    ll ans = 0;
    ll k = 1;
    rep(i, e) {
        k *= (ll) 2;
    }
    ll t = 0;
    for(int i = 1; i <= o; i += 2) {
        t += comb(o, i);
    }
    ans = k * t;
    if(p) {
        cout << ans << endl;
    }
    else {
        ll s = 1;
        rep(i, n) {
            s *= (ll) 2;
        }
        cout << s - ans << endl;
    }
    return 0;
}
