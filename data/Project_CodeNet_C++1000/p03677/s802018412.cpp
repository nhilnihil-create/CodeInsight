//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const ll inf = 1e12 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
int a[N], b[N];
int n, m;
ll pre[N];

int f(int x, int y) {
  return y-x < 0 ? y-x+m : y-x;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  ll ans = 0;
  for (int j = 2; j <= n; j++) {
    int l = a[j-1], r = a[j];
    if (r < l)
      r += m;
    if (r - l > 1) {
      pre[l+2] += 1;
      pre[r+1] -= 1;
      pre[r+1] -= r - l - 1;
      pre[r+2] += r - l - 1;
    }
    ans += r - l;
  }
  ll mx = 0;
  for (int i = 1; i <= 2 * m; i++)
    pre[i] += pre[i-1];
  for (int i = 1; i <= 2 * m; i++)
    pre[i] += pre[i-1];
  for (int i = 1; i <= m; i++)
    mx = max(mx, pre[i] + pre[i+m]);
  printf("%lld\n", ans - mx);
  return 0;
}
