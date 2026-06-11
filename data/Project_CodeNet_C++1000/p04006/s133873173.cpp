#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2000;
int n;
ll x, a[N], b[N], sol;

int rep(int i) {
  if (i < 0) {
    i += n;
  }
  return i;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    sol += a[i];
  }
  for (int i = 1; i <= n; i++) {
    ll cur = x * i;
    for (int j = 0; j < n; j++) {
      int k = rep(j - i);
      b[j] = min(b[j], a[k]);
      cur += b[j];
    }
    sol = min(sol, cur);
  }
  cout << sol << "\n";
}
