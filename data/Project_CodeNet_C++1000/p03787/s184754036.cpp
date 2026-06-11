#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 

const int N = 2e5 + 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}

int n, m, c[N];
vector < int > g[N];
bool used[N], fail;

void dfs(int v, int col) {
  c[v] = col;
  used[v] = 1;
  for (auto to : g[v]) {
    if (used[to]) {
      if (col == c[to]) fail = 1;
    } else dfs(to, col ^ 1);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1;i <= m;i++) {
    int a, b; cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int x = 0, y = 0, z = 0;
  for (int i = 1;i <= n;i++) {
    if (used[i]) continue;
    if (g[i].size() == 0) {
      z++;
      continue;
    }
    fail = 0;
    dfs(i, 0);
    if (!fail) x++;
    else y++;
  }
//  cout << x << " " << y << " " << z << endl;
  ll ans = 1ll * x * x * 2 + 1ll * 2 * x * y + 1ll * y * y;
  ans += 1ll * z * z;
  ans += 2ll * (n - z) * z;
  cout << ans << endl;
}

int main() {
  srand(time(0));
  #ifdef wws
   freopen("in", "r", stdin);
   //freopen("out", "w", stdout);
  #endif 
  //ios_base::sync_with_stdio(0);
  int tt = 1;
  while(tt--) solve();
  return 0;
}