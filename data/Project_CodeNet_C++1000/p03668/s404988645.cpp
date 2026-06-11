#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "


const int N = 1e5+1;
vector<int> g[N];
int n;
int dfs(int cur, int p)
{
  vector<int> sgs;
  for (auto nxt : g[cur])
    if (nxt != p)
      sgs.pb(dfs(nxt, cur));
  int ret = 0;
  for (auto e : sgs) ret ^= (e+1);
  return ret;
 }
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n-1; ++i)
    {
      int u, v; scanf("%d %d", &u, &v);
      g[u].pb(v);
      g[v].pb(u);
    }
  puts(dfs(1, 1)?"Alice":"Bob");
}
