#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

int main() {
  ll n, m, d;
  cin >> n >> m;
  bool flag = true;
  vector<string> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  d = n - m + 1;

  rep(i, d) {
    rep(j, d) {
      flag = true;
      rep(k, m) {
        rep(l, m) {
          if (b[k][l] != a[k + i][l + j]) flag = false;
        }
      }
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
