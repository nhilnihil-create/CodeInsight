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

int g[305][305];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  int ret = 1;
  while(true) {
    set<int> bad;
    vector<int> ord;
    ord.resize(n);
    while(bad.size() < m) {
      map<int, int> dp;
      bool upd = false;
      for(int i = 0; !upd && i < n; i++) {
        while(bad.count(g[i][ord[i]])) ord[i]++;
        if(++dp[g[i][ord[i]]] > ret) {
          upd = true;
          bad.insert(g[i][ord[i]]);
        }
      }
      if(!upd) break;
    }
    if(bad.size() < m) break;
    ret++;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
