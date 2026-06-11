#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  string s;
  cin >> n >> s;

  vll v(n + 1);
  rep(i, n) {
    v[i + 1] = v[i];
    if (s[i] == '(') {
      v[i + 1]++;
    } else {
      v[i + 1]--;
    }
  }

  ll shortage = abs(*min_element(all(v)));
  rep(i, shortage) {
    cout << "(";
  }
  cout << s;
  rep(i, v[n] + shortage) {
    cout << ")";
  }
  cout << endl;

  return 0;
}
