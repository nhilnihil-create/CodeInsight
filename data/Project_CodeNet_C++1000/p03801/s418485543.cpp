#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> isMax(n + 1, false);
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (tmp < a[i]) {
      tmp = a[i];
      isMax[i] = true;
    }
  }
  map<int, int> mp;
  int prv = n - 1;
  vector<long long> ret(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    int crr = a[i];
    mp[crr]++;
    if (isMax[i]) {
      auto bgn = mp.upper_bound(crr);
      for (auto it = bgn; it != mp.end(); it++) {
        int val = it->first;
        int mlt = it->second;
        ret[prv] += (long long)(val - crr) * mlt;
        mp[crr] += mlt;
      }
      mp.erase(bgn, mp.end());
      prv = i;
    }
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int val = it->first;
    int mlt = it->second;
    ret[prv] += (long long)val * mlt;
  }
  for (int i = 0; i < n; i++) {
    cout << ret[i] << '\n';
  }
  return 0;
}