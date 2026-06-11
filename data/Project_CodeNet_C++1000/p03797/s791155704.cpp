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

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll N, ll M) {
  ll result = 0;

  if (M - 2 * N >= 0) {
    result += N;
    M -= N * 2;
  } else {
    result += M / 2;
    M = 0;
  }
  result += M / 4;

  cout << result << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll M;
  scanf("%lld", &M);
  solve(N, M);
  return 0;
}
