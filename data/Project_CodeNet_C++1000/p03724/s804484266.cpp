#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF = 1e9;
const long long INFL = 1LL<<60;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> q(n, 0);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    q[a]++;
    q[b]++;
  }

  for (auto& v : q) {
    if (v % 2 != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
