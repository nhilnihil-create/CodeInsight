// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;
int a[N_MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  long long m = 0;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], m += a[i];
  if (m % (1ll * n * (n + 1) / 2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  m /= 1ll * n * (n + 1) / 2;
  a[0] = a[n];
  for (int i = 1; i <= n; ++i)
    if (m + a[i - 1] - a[i] < 0 || (m + a[i - 1] - a[i]) % n != 0) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
