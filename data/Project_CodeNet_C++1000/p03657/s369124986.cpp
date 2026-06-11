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

void yes() { cout << "Possible" << endl; }
void no() { cout << "Impossible" << endl; }
void yesOrNo(bool flg) {
  if (flg)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}

void solve(ll A, ll B) {
  bool result = A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0;
  yesOrNo(result);
}

int main() {
  ll A;
  scanf("%lld", &A);
  ll B;
  scanf("%lld", &B);
  solve(A, B);
  return 0;
}
