#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  map<int, ll> mp;
  for (int i = 0; i < n; i++) {
    int a;
    ll b;
    cin >> a >> b;
    mp[a] += b;
  }

  for (auto np : mp) {
    if (np.second < k) {
      k -= np.second;
    } else {
      cout << np.first << '\n';
      break;
    }
  }

  return 0;
}
