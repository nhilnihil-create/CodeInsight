#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll f[1000100], s[1000100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n;
  cin >> n;

  f[1] = n;
  s[1] = n;
  f[2] = n * n % mod;
  s[2] = (s[1] + f[2]) % mod;
  FOR(i, 3, n + 1) {
    f[i] = f[i - 1];
    f[i] = (f[i] + (n - 1) * (n - 1)) % mod;
    f[i] = (f[i] + s[i - 3] + n - 1 - (i - 3)) % mod;
    s[i] = (s[i - 1] + f[i]) % mod;
  }
  cout << f[n] << '\n';

  

  




  
  return 0;
}