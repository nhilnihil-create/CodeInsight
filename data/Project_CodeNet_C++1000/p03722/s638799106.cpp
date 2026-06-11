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
const ll inf = 1e16 + 7;
const int N = 1e3 + 5;
const double eps = 1e-9;
vii adj[N];
ll dp[N], dp2[N];

int main() {
  int n, m; scanf("%d %d", &n, &m);
  for (int i =1; i <= m; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    adj[u].pb({v, -w});
  }
  for (int i = 1; i <= n; i++)
    dp[i] = inf;
  dp[1] = 0;
  vector<ll> arr;
  for (int i = 1; i <= 2*m; i++) {
    int fl = 0;
    for (int j = 1; j <= n; j++)
      dp2[j] = dp[j];
    for (int j = 1; j <= n; j++)
      trav(v, adj[j])
        if (dp2[v.st] > dp[j] + (ll)v.nd)
          dp2[v.st] = dp[j] + (ll)v.nd, fl = 1;
    swap(dp2, dp);
    arr.pb(dp[n]);
    if (!fl) break;
    if (i == 2*m) {
      if (dp[n] == arr[m-1])
        break;
      printf("inf\n");
      return 0;
    }
  }
  printf("%lld\n", -dp[n]);
  return 0;
}
