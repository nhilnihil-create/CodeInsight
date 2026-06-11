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
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  map<int, int> m;
  rep(i, h) rep(j, w) m[a[i][j] - 'a']++;
  vector<int> cnt(2, 0);
  if (h % 2 == 1) cnt[0] += w / 2;
  if (w % 2 == 1) cnt[0] += h / 2;
  if (h % 2 == 1 && w % 2 == 1) cnt[1]++;
  rep(i, 26) {
    if (m[i] % 2 == 1) {
      if (cnt[1]-- == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
    if (m[i] % 4 >= 2) {
      if (cnt[0]-- == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;



  return 0;
}