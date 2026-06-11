#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> f(int n) {
  vector<int> res(30);
  for (int i = 0; i < 30; i++) {
    res[i] = (n >> i) & 1;
  }
  return res;
}

int main() {
  int n, k; cin >> n >> k;
  auto K = f(k);
  vector<ll> sum(30);
  ll res = 0;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y; auto X = f(x);
    if (k == (k | x)) res += y;
    for (int i = 29; i >= 0; i--) {
      if (!K[i] && X[i]) break;
      if (K[i] && !X[i]) {
        sum[i] += y;
      }
    }
  }
  cout << max(res, *max_element(sum.begin(), sum.end())) << endl;
}