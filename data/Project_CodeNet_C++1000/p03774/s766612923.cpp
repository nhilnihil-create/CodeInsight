#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];
  vector<int> c(m), d(m);
  rep(i,m) cin >> c[i] >> d[i];
  rep(i,n) {
    int ans = INF;
    int p = -1;
    rep(j,m) {
      int t = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (t < ans) {
        ans = t;
        p = j + 1;
      }
    }
    cout << p << endl;
  }
}

int main() {
  solve();
  return 0;
}