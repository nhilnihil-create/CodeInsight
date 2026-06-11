#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string A;
  cin >> A;
  vector<ll> cs(26);
  ll n = A.size();

  for (char c : A)
    cs[c - 'a']++;

  ll res = n * (n - 1) / 2 + 1;

  for (ll x : cs) {
    res -= x * (x - 1) / 2;
  }

  cout << res << endl;
}
