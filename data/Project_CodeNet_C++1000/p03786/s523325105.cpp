#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> a;

bool ok(int idx) {
  ll cur = a[idx];
  for (int i = 0; i < n; ++i) {
    if (i == idx) continue;
    if (a[i] > (cur * 2)) return false;
    cur += a[i];
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  int left = -1, right = n;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (ok(mid)) right = mid;
    else left = mid;
  }
  int ans = n - right;
  cout << ans << '\n';
  return 0;
}
