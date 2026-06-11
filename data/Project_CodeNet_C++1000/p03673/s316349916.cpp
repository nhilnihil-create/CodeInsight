#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  vector<int> b(n);
  if (n % 2 == 0) {
    rep(i, n / 2) {
      b[i] = a[n - 1 - 2 * i];
      b[n / 2 + i] = a[2 * i];
    }
  } else {
    b[n / 2] = a[0];
    rep(i, n / 2) {
      b[i] = a[n - 1 - 2 * i];
      b[n / 2 + 1 + i] = a[2 * i + 1];
    }
  }
  printf("%d", b[0]);
  for (int i = 1; i < n; ++i) printf(" %d", b[i]);
  printf("\n");
  return 0;
}