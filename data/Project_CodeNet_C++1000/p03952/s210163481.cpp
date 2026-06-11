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



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n, x;
  cin >> n >> x;

  if (n == 2) {
    if (x == 2) {
      cout << "Yes\n";
      rep(i, 3) cout << i + 1 << '\n';
    }
    else cout << "No\n";
    return 0;
  }
  if (x == 1 || x == 2 * n - 1) {
    cout << "No\n";
    return 0;
  }
  vector<int> a(2 * n - 1, 0);
  vector<bool> used(2 * n, false);
  a[n - 1] = x;
  used[x] = true;
  if (x == 2) {
    a[n - 2] = 1;
    a[n - 3] = 3;
    a[n] = 4;
    used[1] = true, used[3] = true, used[4] = true;
  }
  else {
    a[n - 2] = 2 * n - 1;
    a[n - 3] = 1;
    a[n] = 2;
    used[1] = true, used[2] = true, used[2 * n - 1] = true;
  }
  int res = 1;
  rep(i, 2 * n - 1) {
    if (a[i]) continue;
    while (used[res]) res++;
    a[i] = res;
    used[res] = true;
  }
  cout << "Yes\n";
  rep(i, 2 * n - 1) cout << a[i] << '\n';



  
  return 0;
}