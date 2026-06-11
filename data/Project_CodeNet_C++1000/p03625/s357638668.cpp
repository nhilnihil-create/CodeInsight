#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                         \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

void solve(ll N, std::vector<ll> A) {
  map<ll, ll> c;
  ll m1 = 0, m2 = 0;

  rep(i, N) {
    ll v = A.at(i);
    if (c.count(v)) {
      c.at(v)++;
      if (c.at(v) == 2 || c.at(v) == 4) {
        if (v > m1) {
          m2 = m1;
          m1 = v;
        } else if (v > m2) {
          m2 = v;
        }
      }
    } else {
      c[v] = 1;
    }
  }

  cout << m1 * m2 << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  std::vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
