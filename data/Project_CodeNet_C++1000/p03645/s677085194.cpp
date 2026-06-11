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
  vector<int> v(n);
  vector<int> u(n);
  u[n-1] = 1;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a == 0) v[b]++;
    if (b == n-1) u[a]++;
  }

  rep(i,n) {
    if (v[i] && u[i]) {
      cout << "POSSIBLE" << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main() {
  solve();
  return 0;
}