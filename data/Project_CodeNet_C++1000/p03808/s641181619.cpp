#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  if (sum % (n * (n + 1) / 2) != 0) {
    cout << "NO\n";
    return 0;
  }
  
  ll count = sum / (n * (n + 1) / 2), count2 = 0;
  for (int i = 0; i < n; i++) {
    ll dif = a.at(i) - a.at((i - 1 + n) % n);
    dif -= count;
    dif *= -1;
    if (dif < 0 || dif % n != 0) {
      cout << "NO\n";
      return 0;
    }
    count2 += dif / n;
  }
  
  if (count == count2) cout << "YES\n";
  else cout << "NO\n";
}