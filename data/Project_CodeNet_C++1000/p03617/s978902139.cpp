#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define repi(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define uniqueV(x)                                                             \
  sort(x.begin(), x.end());                                                    \
  x.erase(unique(x.begin(), x.end()), x.end());
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y)                                                           \
  cerr << "(" << #x << ", " << #y << ") = "                                    \
       << "(" << x << ", " << y << ")" << '\n'

typedef long long int ll;
typedef pair<int, int> P;

const long long INF = 3e18 + 12;
const int inf = 1e9;

// ----------------------------------------------

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  ll qa = q * 8;
  ll ha = h * 4;
  ll sa = s * 2;

  vector<ll> v = {qa, ha, sa, d};

  sort(all(v));

  ll sum = 0;

  for (int i : v) {
    debug(i);

    double ama = 0;
    if (i == qa) {
      int a = n / 0.25;
      sum += a * q;
      ama = fmod(n, 0.25);
    } else if (i == ha) {
      int a = n / 0.5;
      sum += a * h;
      ama = fmod(n, 0.5);
    } else if (i == sa) {
      int a = n / 1;
      sum += a * s;
      ama = n % 1;
    } else if (i == d) {
      int a = n / 2;
      debug(a);
      sum += a * d;
      ama = n % 2;
    }

    if (ama == 0) { break; }

    n = ama;
  }

  cout << sum << endl;
  return 0;
}