#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll a[100010];
ll b[100010];
ll c[100010];
bool d[100010];
ll ans = 1;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  c[0] = a[0];
  d[0] = 1;
  for (int i = 1; i < n; i++) {
    c[i] = a[i];
    if (a[i] != a[i - 1]) {
      d[i] = 1;
    }
  }
  if (c[n - 1] < b[n - 1] || (d[n - 1] && b[n - 1] != c[n - 1])) {
    puts("0");
    return 0;
  }
  c[n - 1] = b[n - 1];
  d[n - 1] = 1;
  for (int j = n - 2; j >= 0; j--) {
    if (b[j] != b[j + 1]) {
      if (d[j]) {
        if (b[j] != c[j]) {
          puts("0");
          return 0;
        }
      } else {
        if (c[j] < b[j]) {
          puts("0");
          return 0;
        } else {
          c[j] = b[j];
          d[j] = 1;
        }
      }
    } else {
      if (d[j]) {
        if (b[j] < c[j]) {
          puts("0");
          return 0;
        }
      } else {
        c[j] = min(c[j], b[j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!d[i]) {
      ans *= c[i];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
