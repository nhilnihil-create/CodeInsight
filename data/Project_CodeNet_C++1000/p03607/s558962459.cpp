#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if(a.count(ai)) a[ai]++;
    else a[ai] = 1;
  }
  int ans = 0;
  for (auto p: a) {
    if(p.second % 2 == 1) ans++;
  }
  cout << ans;
}