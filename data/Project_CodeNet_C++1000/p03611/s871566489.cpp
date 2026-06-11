#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++, mp[x - 1]++, mp[x + 1]++;
  }
  int ans = 0;
  for (auto p : mp) {
    ans = max (p.second, ans);
  }
  cout << ans;

}
