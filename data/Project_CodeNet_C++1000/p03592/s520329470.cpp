#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

bool solve(const int& n, const int& m, const int& k) {
  if (k % n == 0 || k % m == 0 || k == 0) {
    return true;  
  }

  for (int i = 1; i <= n; i++) {
    int blk = m * i;
    if (blk == k) return true;
    for (int j = 0; j < m; j++) {
      blk += n - i * 2;
      if (blk == k) return true;  
    }
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  if (solve(n, m, k) || solve(m, n, k)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
