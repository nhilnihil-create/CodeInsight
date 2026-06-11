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
typedef pair<ll, int> query;
typedef vector<vector<ll>> matrix;

vector<int> children[100005];
int n;

int solve(int curr) {
  vector<int> ret;
  for(int out: children[curr]) {
    ret.push_back(solve(out));
  }
  sort(ret.begin(), ret.end());
  reverse(ret.begin(), ret.end());
  int ans = ret.size();
  int idx = 1;
  for(int out: ret) {
    ans = max(ans, idx+++out);
  }
  return ans;
}

void solve() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int par;
    cin >> par;
    children[par].push_back(i);
  }
  cout << solve(1) << "\n";
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
