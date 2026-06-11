#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x[i] = xx - a;
  }
  map<int, ll> num1, num2, num3;
  int n1 = n / 3, n2 = (n + 1) / 3, n3 = (n + 2) / 3;

  for (int i = 0; i < (1 << n1); i++) {
    ll sum_x = 0;
    for (int j = 0; j < n1; j++) {
      if (i & (1 << j)) {
        sum_x += x[j];
      }
    }
    num1[sum_x]++;
  }

  for (int i = 0; i < (1 << n2); i++) {
    ll sum_x = 0;
    for (int j = 0; j < n2; j++) {
      if (i & (1 << j)) {
        sum_x += x[n1 + j];
      }
    }
    num2[sum_x]++;
  }

  for (int i = 0; i < (1 << n3); i++) {
    ll sum_x = 0;
    for (int j = 0; j < n3; j++) {
      if (i & (1 << j)) {
        sum_x += x[n1 + n2 + j];
      }
    }

    num3[sum_x]++;
  }

  ll ans = 0;
  for (auto p1: num1) {
    for (auto p2: num2) {
      ans += p1.second * p2.second * num3[-(p1.first + p2.first)];
    }
  }
  cout << ans - 1 << endl;

  return 0;
}