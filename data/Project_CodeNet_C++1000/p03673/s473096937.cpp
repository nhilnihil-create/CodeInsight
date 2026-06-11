#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) {
    cin >> a[i];
  }

  int l = 0;
  int r = n - 1;
  bool useL = true;
  for (int i = n - 1; i >= 0; --i) {
    if (useL) {
      b[l] = a[i];
      l++;
      useL = false;
    } else {
      b[r] = a[i];
      r--;
      useL = true;
    }
  }

  rep(i, n) {
    if (i != 0) printf(" ");
    printf("%lld", b[i]);
  }

  printf("\n");
  
  return 0;
}