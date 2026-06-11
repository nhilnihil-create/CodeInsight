#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x.at(i);
  
  sort(x.begin(), x.end());
  
  map<int, int> mp1, mp2;
  // mp1[i]:mで割った余りがiのカードが何枚あるか
  // mp2[i]:mで割った余りがiのカードだけで同じ整数をペアにしたとき, 最大何ペアできるか
  for (int i = 0; i < n; i++) mp1[x.at(i) % m]++;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (x.at(i - 1) == x.at(i)) count++;
    else {
      mp2[x.at(i - 1) % m] += count / 2;
      count = 1;
    }
  }
  mp2[x.back() % m] += count / 2;
  
  int ans = 0;
  for (int i = 0; i <= m / 2; i++) {
    if (i == 0 || (m % 2 == 0 && i == m / 2)) {
      ans += mp1[i] / 2;
    }
    else {
      int keep = min(mp1[i], mp1[m - i]);
      ans += keep;
      mp1[i] -= keep;
      mp1[m - i] -= keep;
      if (mp1[i] > 0) {
        ans += min(mp1[i] / 2, mp2[i]);
      }
      else if (mp1[m - i] > 0) {
        ans += min(mp1[m - i] / 2, mp2[m - i]);
      }
    }
  }
  
  cout << ans << '\n';
}