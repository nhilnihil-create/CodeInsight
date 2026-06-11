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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  rep(i, n) {
    cin >> x[i].first;
    x[i].first--;
    x[i].second = i;
  }

  sort(x.begin(), x.end());
  rep(i, n - 1) {
    if (x[i].first == x[i + 1].first) {
      cout << "No\n";
      return 0;
    }
  }
  vector<int> ans(n * n, -1), cnt(n, 0);
  rep(i, n) ans[x[i].first] = x[i].second;
  int idx = 0;
  rep(i, n) {
    while (cnt[x[i].second] < x[i].second) {
      if (idx == x[i].first) {
        cout << "No\n";
        return 0;
      }
      if (ans[idx] != -1) {
        idx++;
        continue;
      }
      ans[idx] = x[i].second;
      cnt[x[i].second]++;
      idx++;
    }
  }
  cnt.assign(n, n - 1);
  idx = n * n - 1;
  repr(i, n - 1){
    while (cnt[x[i].second] > x[i].second) {
      if (idx == x[i].first) {
        cout << "No\n";
        return 0;
      }
      if (ans[idx] != -1) {
        idx--;
        continue;
      }
      ans[idx] = x[i].second;
      cnt[x[i].second]--;
      idx--;
    }
  }
  cout << "Yes\n";
  rep(i, n * n) cout << ans[i] + 1 << ' ';
  cout << '\n';
  


  




  
  return 0;
}