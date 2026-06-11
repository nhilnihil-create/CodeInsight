#include <bits/stdc++.h>
using namespace std;


void solve() {
  map<int, int> mp;
  int x;
  for(int i = 0; i < 3; i++) {
    cin >> x;
    mp[x]++;
  }
  cout << mp.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
