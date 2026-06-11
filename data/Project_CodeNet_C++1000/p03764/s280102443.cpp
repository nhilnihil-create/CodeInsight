#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 100005;
char en = '\n';
ll inf = 1e17;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

ll n, q;
ll nxt[N][30];
char arr[N];
ll dp[255][255][255];

string a, b, c;

ll recur(ll posa, ll posb, ll posc) {

  if (posa == 0 && posb == 0 && posc == 0)
    return 0;
  ll &ans = dp[posa][posb][posc];
  if (ans != -1)
    return ans;

  ans = n + 1;
  if (posa) {
    ll len = recur(posa - 1, posb, posc);
    //  cout << posa << " " << len << endl;
    ans = min(ans, nxt[len + 1][a[posa] - 'a']);
  }
  if (posb) {
    ll len = recur(posa, posb - 1, posc);
    ans = min(ans, nxt[len + 1][b[posb] - 'a']);
  }
  if (posc) {
    ll len = recur(posa, posb, posc - 1);
    ans = min(ans, nxt[len + 1][c[posc] - 'a']);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  ll sum1 = 0;
  ll sum2 = 0;
  for (ll i = 1; i <= n; i++) {
    ll x;
    cin >> x;

    x = (x % mod + mod) % mod;
    sum2 += x;
    sum2 = (sum2 % mod + mod) % mod;

    sum1 += i * x % mod - sum2;
    sum1 = (sum1 % mod + mod) % mod;
  }

  ll stx = sum1;

  sum1 = 0;
  sum2 = 0;
  for (ll i = 1; i <= m; i++) {
    ll x;
    cin >> x;
    x = (x % mod + mod) % mod;
    sum2 += x;

    sum2 = (sum2 % mod + mod) % mod;

    sum1 += i * x % mod - sum2;
    sum1 = (sum1 % mod + mod) % mod;
  }

  cout << stx * sum1 % mod << en;

  return 0;
}