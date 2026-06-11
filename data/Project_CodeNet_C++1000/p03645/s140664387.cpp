// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n, m; cin >> n >> m;
  vector<int> G[200000];
  loop(i,0,m) {
    int a, b;
    cin >> a >> b; a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  for (auto v: G[0]) {
    for (auto u: G[v]) {
      if (u == n-1) {
      cout << "POSSIBLE" << endl;
      return 0;
      }
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
