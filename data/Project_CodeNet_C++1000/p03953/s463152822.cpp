#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ll N = 1e5 + 10;

ll n, m; ll k;
ll x[N], a[N], b[N], c[N];
ll st[N][61];

int main() {
  scanf("%lld", &n);
  for (ll i = 1; i <= n; i++) {
    b[i] = i;
    scanf("%lld", &x[i]);
  }
  scanf("%lld %lld", &m, &k);
  for (ll i = 1; i <= m; i++) {
    scanf("%lld", &a[i]);
    swap(b[a[i] - 1], b[a[i]]);
  }
  for (ll i = 1; i < n; i++) st[b[i]][0] = i;
  for (ll j = 1; j < 61; j++)
    for (ll i = 1; i < n; i++)
      st[i][j] = st[st[i][j - 1]][j - 1];
  for (ll i = 1; i < n; i++) {
    ll cur = i;
    for (ll j = 0; j < 61; j++) {
      if ((k >> j) & 1) {
        cur = st[cur][j];
      }
    }
    c[cur + 1] = x[i + 1] - x[i];
  }
  c[1] = x[1];
  for (ll i = 2; i <= n; i++) c[i] += c[i - 1];
  for (ll i = 1; i <= n; i++) printf("%lld\n", c[i]);
  return 0;
}