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
const int inf = 1e8;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int H, W, h, w;
  cin >> H >> W >> h >> w;

  if (H % h == 0 && W % w == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  if (W % w != 0) {
    vector<int> s(W + 1, 0);
    FOR(i, 1, W + 1) {
      s[i] = (i < w ? inf : s[i - w] - 1);
    }
    rep(i, H) {
      rep(j, W) {
        cout << s[j + 1] - s[j] << ' ';
      }
      cout << '\n';
    }
    return 0;
  }
  if (H % h != 0) {
    vector<int> s(H + 1, 0);
    FOR(i, 1, H + 1) {
      s[i] = (i < h ? inf : s[i - h] - 1);
    }
    rep(i, H) {
      rep(j, W) {
        cout << s[i + 1] - s[i] << ' ';
      }
      cout << '\n';
    }
    return 0;
  }


  




  
  return 0;
}