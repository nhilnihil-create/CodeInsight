#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  
  ll dif = abs(a - b);
  
  for (int i = 0; i < n - 1; i++) {
    ll high = i * d - (n - 1 - i) * c;
    ll low = i * c - (n - 1 - i) * d;
    if (low <= dif && dif <= high) {
      cout << "YES\n";
      return 0;
    }
  }
  
  cout << "NO\n";
  return 0;
}