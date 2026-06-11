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

bool check(string t) {
  rep(i, t.length()) {
    if (t[i] == '0') return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  string s;
  cin >> s;

  int ans = inf;
  rep(i, 26) {
    char c = 'a' + i;
    string t;
    rep(i, s.length()) t += (s[i] == c ? '1' : '0');
    //cout << t << '\n';
    int res = 0;
    while (check(t)) {
      res++;
      string nxtt;
      rep(i, t.length() - 1) {
        if (t[i] == '1' || t[i + 1] == '1') nxtt += '1';
        else nxtt += '0';
      }
      t = nxtt;
    }
    chmin(ans, res);
  }
  cout << ans << '\n';




  
  return 0;
}