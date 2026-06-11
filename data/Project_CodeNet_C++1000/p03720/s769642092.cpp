#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int n, m;
  cin >> n >> m;

  unordered_map<int, int> mp;

  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    mp[u]++, mp[v]++;
  }

  for (int i = 1; i <= n; ++i) {
    cout << mp[i] << "\n";
  }
}
