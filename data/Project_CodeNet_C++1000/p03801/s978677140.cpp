#include <bits/stdc++.h>
using namespace std;
inline void chmin (int& a, int b) {
  if (a > b) a = b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> dat(n);
  for (int i = 0; i < n; i++) {
    cin >> dat[i].first;
    dat[i].second = i;
  }
  sort(dat.begin(), dat.end());
  vector<long long> ret(n);
  int mini = n;
  for (int i = n - 1; i >= 1; i--) {
    int crr = dat[i].first;
    int nxt = dat[i - 1].first;
    int ind = dat[i].second;
    chmin(mini, ind);
    ret[mini] += (long long)(crr - nxt) * (n - i);
  }
  ret[0] += (long long)dat[0].first * n;
  for (int i = 0; i < n; i++) {
    cout << ret[i] << '\n';
  }
  return 0;
}