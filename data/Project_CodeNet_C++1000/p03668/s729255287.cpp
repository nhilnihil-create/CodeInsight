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
typedef pair<pii, int> ppiii;

vector<int> edges[100005];

int dfs(int curr, int par=-1) {
  int ans = 0;
  int sz = 0;
  for(int out: edges[curr]) {
    if(out == par) continue;
    ans ^= dfs(out, curr)+1;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int ret = dfs(1);
  if(ret != 0) cout << "Alice\n";
  else cout << "Bob\n";
}

void casesolve() {
  int t;
  cin >> t;
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
