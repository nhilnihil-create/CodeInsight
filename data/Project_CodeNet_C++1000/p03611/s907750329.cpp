#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];
  map<int, long long> mp;

  for (int i=0; i<n; i++) {
    mp[a[i]]++;
    mp[a[i] - 1]++;
    mp[a[i] + 1]++;
  }
  long long ans = 0;
  for (auto it : mp) {
    ans = max(ans, it.second);
  }
  cout << ans;
  return 0;
}