#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a (n);
  ll sum = 0, mx = ((ll)n * (n + 1)) / 2;
  for (auto &i : a) cin >> i, sum += i;

  if (sum % mx != 0) {
    cout << "NO\n";
    return 0;
  }

  ll k = sum / mx;

  for (int i = 1; i < n; i++) {
    int d = a[i] - a[i - 1];
    ll val = k - d;
    if (val < 0 || val % n != 0) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
}
