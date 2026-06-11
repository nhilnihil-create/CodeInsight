#include <bits/stdc++.h>
using namespace std;



void solve() {
  long long int n, t;
  cin >> n >> t;
  long long int a, b;
  long long int total = 0;
  cin >> b;
  for (int i = 1; i < n; i++) {
    cin >> a;

    total += min(t, (a - b));
    b = a;
  }
  cout << total + t;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
