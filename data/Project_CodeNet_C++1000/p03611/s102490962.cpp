#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(100000, 0);
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    if(ai != 0) a[ai - 1]++;
    a[ai]++;
    if(ai != 99999) a[ai + 1]++;
  }
  int ans = 0;
  for (int i = 0; i < 100000; i++) {
    ans = max(ans, a[i]);
  }
  cout << ans;
}