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

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void yesOrNo(bool flg) {
  if (flg)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

void showVec(string name, std::vector<ll> x) {
  cerr << name << ": ";
  for (auto v : x) {
    cerr << v << " ";
  }
  cerr << endl;
}

void solve(ll N, std::vector<ll> a) {
  bool result = false;

  ll c0 = 0;
  ll c1 = 0;
  ll c4 = 0;
  rep(i, N) {
    if (a.at(i) % 4 == 0) {
      c4++;
    } else if (a.at(i) % 2 == 0) {
      c1++;
    } else {
      c0++;
    }
  }

  if (c1 == 0) {
    result = c4 + 1 >= c0;
  } else {
    result = c4 >= c0;
  }
  yesOrNo(result);
}

int main() {
  ll N;
  scanf("%lld", &N);
  std::vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, std::move(a));
  return 0;
}
