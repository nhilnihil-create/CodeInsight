#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll tmp0 = 0;
  ll tmp1 = 0;
  ll sum0 = 0;
  ll sum1 = 0;
  // + - + -...
  for (int i = 0; i < n; i++) {
    sum0 += a[i];
    sum1 += a[i];

    if(i % 2 == 0) {
      if(sum0 <= 0) {
        ll adj = 1 - sum0;
        tmp0 += abs(adj);
        sum0 = 1;
      }
    } else {
      if(sum0 >= 0) {
        ll adj = -1 - sum0;
        tmp0 += abs(adj);
        sum0 = -1;
      }
    }

    if(i % 2 == 1) {
      if(sum1 <= 0) {
        ll adj = 1 - sum1;
        tmp1 += abs(adj);
        sum1 = 1;
      }
    } else {
      if(sum1 >= 0) {
        ll adj = -1 - sum1;
        tmp1 += abs(adj);
        sum1 = -1;
      }
    }
  }
  cout << min(tmp0, tmp1) << endl;
}