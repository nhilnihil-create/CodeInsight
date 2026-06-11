#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes() {
  cout << "YES" << endl;
  exit(0);
}

void no() {
  cout << "NO" << endl;
  exit(0);
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  ll sum = 0;
  REP(i, n) sum += a[i];
  if (sum % (n * (n + 1) / 2) != 0) {
    no();
  }
  auto idx = [&](ll i) { return (i + n) % n; };
  ll k = sum / (n * (n + 1) / 2);
  REP(i, n) {
    ll d = k + a[idx(i)] - a[idx(i + 1)];
    if (d % n != 0) no();
    ll t = d / n;
    if (t < 0 || k < t) no();
  }
  yes();
}