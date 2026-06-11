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
const ll inf = 1e14 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
int a[N], vis[N], b[N], nb[N];

int main() {
  int n, x; scanf("%d %d", &n, &x);
  ll ans = inf, sm = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), b[i] = a[i], sm += b[i];
  ans = min(ans, sm);
  for (int i = 1; i < n; i++) {
    nb[1] = min(b[n], a[1]);
    for (int j = 2; j <= n; j++)
      nb[j] = min(b[j-1], a[j]);
    swap(b, nb);
    sm = 0;
    for (int j = 1; j <= n; j++)
      sm += b[j];
    ans = min(ans, sm + i * 1ll * x);
  }
  printf("%lld\n", ans);
  return 0;
}
