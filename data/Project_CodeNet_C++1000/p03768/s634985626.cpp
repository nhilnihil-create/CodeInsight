#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

vector<int> edges[100005];

int v[100005];
int d[100005];
int c[100005];

int ret[100005];

int dp[100005];

void color(int curr, int dist, int cc) {
  if(dp[curr] >= dist) return;
  dp[curr] = dist;
  if(ret[curr] == 0) ret[curr] = cc;
  color(curr, dist-1, cc);
  for(int out: edges[curr]) color(out, dist-1, cc);
}

void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) dp[i] = -1;
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) cin >> v[i] >> d[i] >> c[i];
  for(int i = q-1; i >= 0; i--) {
    color(v[i], d[i], c[i]);
  }
  for(int i = 1; i <= n; i++) cout << ret[i] << "\n";
}

void casesolve() {
  int t;
  cin >> t; cin.ignore();
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
