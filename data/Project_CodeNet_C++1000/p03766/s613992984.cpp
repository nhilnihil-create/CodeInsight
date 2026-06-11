#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5, base = 1e9 + 7;

int f[maxn];
int n;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  f[0] = 0;
  f[1] = n;
  f[2] = 1ll * n * n % base;
  int sum = 0;
  for (int i = 3; i <= n; i++) {
    f[i] = (f[i - 1] + 1ll * (n - 1) * (n - 1) % base) % base;
    f[i] = (f[i] + sum + n - i + 2) % base;
    sum = (sum + f[i - 2]) % base;
  }
  cout << f[n] << '\n';
}
