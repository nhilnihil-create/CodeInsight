#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> g(N);
  vector<ll> a(M), b(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  queue<pair<ll, ll>> q;
  q.push({0, 2});
  bool reachable = false;
  while (!q.empty()) {
    ll cur = q.front().first;
    ll cnt = q.front().second;
    q.pop();
    if (cur == N - 1) {
      reachable = true;
      break;
    }
    if (cnt == 0) {
      continue;
    }
    cnt--;
    for (int i = 0; i < g[cur].size(); i++) {
      q.push({g[cur][i], cnt});
    }
  }
  string ans = (reachable) ? "POSSIBLE" : "IMPOSSIBLE";
  cout << ans << endl;
  return 0;
}