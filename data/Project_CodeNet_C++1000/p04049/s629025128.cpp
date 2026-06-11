#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

vector<int> edges[2001];

int dfs(int curr, int par, int depth) {
  if(depth == 0) return 1;
  int ret = 1;
  for(int out: edges[curr]) {
    if(out == par) continue;
    ret += dfs(out, curr, depth-1);
  }
  return ret;
}

void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int maxIn = 0;
  if(k%2 == 0) {
    for(int i = 1; i <= n; i++) {
      maxIn = max(maxIn, dfs(i, -1, k/2));
    }
  }
  else {
    for(int i = 1; i <= n; i++) {
      for(int out: edges[i]) {
        maxIn = max(maxIn, dfs(i, out, k/2) + dfs(out, i, k/2));
      }
    }
  }
  cout << n - maxIn << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
