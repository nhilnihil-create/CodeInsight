#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n, k, l[n];
  cin >> n >> k;
  rep(i, n) cin >> l[i];
  sort(l, l + n, greater<int>());
  int ans = 0;
  rep(i, k) ans += l[i];
  cout << ans << endl;
}