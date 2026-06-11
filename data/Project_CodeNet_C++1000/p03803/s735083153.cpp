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

void solve(ll A, ll B) {
  ll a = A == 1 ? A + 13 : A;
  ll b = B == 1 ? B + 13 : B;

  if (a > b)
    cout << "Alice" << endl;
  else if (a < b)
    cout << "Bob" << endl;
  else
    cout << "Draw" << endl;
}

int main() {
  ll A;
  scanf("%lld", &A);
  ll B;
  scanf("%lld", &B);
  solve(A, B);
  return 0;
}
