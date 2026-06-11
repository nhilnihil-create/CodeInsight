#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  map<ll, ll> mp;
  for (int i = 2; i <= n; i++) {
    int now = i;
    for (int j = 2; j * j <= i; j++) {
      while (now % j == 0) {
        mp[j]++;
        now /= j;
      }
    }
    if (now != 1) mp[now]++;
  }
  
  ll ans = 1;
  for (auto i : mp) {
    // cout << i.first << " " << i.second << endl;
    ans *= i.second + 1;
    ans %= MOD;
  }
  
  cout << ans << '\n';
}