#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  ll n; cin >> n;
  ll i = 0;
  ll ans = 1e10;
  while (i*i < n) {
    i++;
    ll cost = 1e10;;
    if (n % i == 0) {
      string a = to_string(i);
      string b = to_string(n/i);
      if (a.size() < b.size()) {
        cost = b.size();
      } else {
        cost = a.size();
      }
    }
    if (cost < ans) ans = cost;
  }
  cout << ans << endl;
}
