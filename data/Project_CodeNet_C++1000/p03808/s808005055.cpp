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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  if (n == 2) {
    sort(a.begin() ,a.end());
    if ((a[0] + a[1]) % 3 != 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (a[1] - a[0] > a[0]) {
      cout << "NO" << endl;
      return 0;
    }
    else {
      cout << "YES" << endl;
      return 0;
    }
  }
  a.push_back(a[0]);
  ll diff = -1, cnt = 0, a0 = 0;
  rep(i, n) {
    a[i + 1] += n * cnt;
    if (a[i + 1] - a[i] <= 0) {
      ll rescnt = (a[i] - a[i + 1]) / n + 1;
      cnt += rescnt;
      a0 += (n - i) * rescnt;
      a[i + 1] += n * rescnt;
    }
    if (diff == -1) diff = a[i + 1] - a[i];
    else if (diff != a[i + 1] - a[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (a0 != a[0]) {
    if (a0 > a[0]) {
      cout << "NO" << endl;
      return 0;
    }
    else {
      if ((a[0] - a0) % (n * (n + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;








  
  return 0;
}