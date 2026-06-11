#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> counts(1001);

// 約数をcountsに入れる
void helper(int n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    ll count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    counts[i] += count;
  }
  if (n > 1) {
    counts[n]++;
  }
}

int main() {
  ll mod = pow(10, 9) + 7;
  ll n;
  cin >> n;
  for (ll i = 2; i <= n; i++) {
    helper(i);
  }
  ll v = 1;
  for (ll i = 2; i <= n; i++) {
    v *= (counts[i] + 1);
    v %= mod;
  }
  cout << v << endl;
}
