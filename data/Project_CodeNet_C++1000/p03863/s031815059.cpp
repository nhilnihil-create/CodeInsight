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
  cout << "First" << endl;
  exit(0);
}

void no() {
  cout << "Second" << endl;
  exit(0);
}

int main() {
  string s;
  cin >> s;
  ll n = SZ(s);
  bool b1 = n % 2 == 0;
  bool b2 = s[0] == s[n - 1];
  if (b1 == b2) yes();
  no();
}