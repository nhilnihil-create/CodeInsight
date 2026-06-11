#include <bits/stdc++.h>
 
using namespace std;
 
#define f0r(a, b) for (long long a = 0; a < (b); a++)
#define f1r(a, b, c) for (long long a = (b); a < (c); a++)
#define f0rd(a, b) for (long long a = (b); a >= 0; a--)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define mp make_pair
#define f first
#define s second
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vpl = vector<pll>;
 
void fio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const long double pi = 3.14159265358979323846;



void solve() {
  ll n; cin >> n;

  ll mat[n][n];
  f0r(i, n) f0r(j, n) cin >> mat[i][j];

  ll v = n * (n - 1) / 2;
  pair<ll, pll> dists[v];
  ll c = 0;
  f0r(i, n) f0r(j, i) {
    dists[c++] = mp(mat[i][j], mp(i, j));
  }
  sort(dists, dists + v);

  ll ans = 0;
  f0r(i, v) {
    pair<ll, pll> k = dists[i];
    pll p = k.s;
    bool cur = 0;
    f0r(j, n) {
      if (j == p.f || j == p.s) continue;
      if (mat[p.f][j] + mat[j][p.s] < mat[p.f][p.s]) {
        cout << -1 << '\n';
        return;
      } else if (mat[p.f][j] + mat[j][p.s] == mat[p.f][p.s]) {
        cur = 1;
      }
    }
    if (!cur) ans += mat[p.f][p.s];
  }
  cout << ans << '\n';
}
 
int main() {
  fio();
  
  int T = 1;
  // cin >> T;
  while (T--) solve();
} 