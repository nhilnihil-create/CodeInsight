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
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;
typedef pair<ll, pii> key;

vector<int> edges[100005];
int k;
int ret;

int dfs(int curr) {
  int maxD = 0;
  for(int out: edges[curr]) {
    int d = dfs(out);
    if(d == k-1 && curr != 1) ret++;
    else maxD = max(maxD, d+1);
  }
  return maxD;
}

void solve() {
  int n;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    int to;
    cin >> to;
    if(i == 1 && to != 1) ret++;
    if(i > 1) edges[to].push_back(i);
  }
  dfs(1);
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
