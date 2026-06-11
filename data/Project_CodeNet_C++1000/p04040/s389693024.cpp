/*
❤️❤️❤️I_love_QMsh❤️❤️❤️
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // <int> .find_by_order(int) .order_of_key(int)

template<typename T> bool smin(T &a, const T &b) { bool ret = b < a; return a = (ret ? b : a), ret; }
template<typename T> bool smax(T &a, const T &b) { bool ret = a < b; return a = (ret ? b : a), ret; }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd;

const int M = (int)1e9 + 7;

int bpow(int n, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) {
      res = (1ll * res * n) % M;
    }
    n = (1ll * n * n) % M;
    p /= 2;
  }
  return res;
}

const int N = 2e5 + 30;
int f[N];
int invf[N];

int cnk(int n, int k) {
  return (1ll * f[n] * invf[k] % M) * invf[n - k] % M;
}


signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  f[0] = 1;
  invf[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = (1ll * f[i - 1] * i) % M;
    invf[i] = bpow(f[i], M - 2);
  }


  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int ans = cnk(n + m - 2, n - 1);
  for (int i = 0; i < b; i++) {
    ans = ((ans - 1ll * cnk(i + n - a - 1, i) * cnk(m - i + a - 2, a - 1)) % M + M) % M;
  }
  cout << ans;

  return 0;
}