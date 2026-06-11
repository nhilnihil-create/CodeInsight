#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  int a[n];
  int sum_all = 0;
  rep(i, n) {
    cin >> a[i];
    sum_all += a[i];
  }
  if (sum_all % 10 != 0) {
    cout << sum_all << endl;
  } else {
    int sum = 0;
    rep(i, n) {
      if (a[i] % 10 != 0) {
        sum = max(sum, sum_all - a[i]);
      }
    }
    cout << sum << endl;
  }
  return 0;
}