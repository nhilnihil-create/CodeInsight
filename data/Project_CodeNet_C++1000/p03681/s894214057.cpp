#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;

  if (abs(n-m) >= 2){
    cout << 0 << endl;
    return 0;
  }
  int64_t res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
    res %= mod;
  }
  for(int i = 1; i <= m; i++){
    res *= i;
    res %= mod;
  }
  if (n == m) res *= 2;
  cout << res % mod << endl;
  return 0;
}