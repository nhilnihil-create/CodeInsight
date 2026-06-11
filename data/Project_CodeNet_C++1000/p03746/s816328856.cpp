#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define X first
#define Y second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define MAXN 100100

int n, m;
vector<int> g[MAXN];
vector<int> r[3];
int bio[MAXN];

void dfs(int cv, int x)
{//cout<<cv+1<<' '<<x<<endl;
  bio[cv] = 1;
  r[x].pb(cv);

  for (int i: g[cv]) {
    //cout<<i<<' ';
    if (!bio[i]) {
      //cout << cv + 1 << "->" << i + 1 << ' ' << x << endl;
      dfs(i, x);
      return;
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  int ver = -1;
  for (int i = 0; i < n; i++) {
    if (g[i].size())
      ver = i;
  }
  dfs(ver, 1);
  for (int i: g[ver])
    if (!bio[i]) {
      dfs(i, 2);
      break;
    }
  printf("%d\n", r[1].size() + r[2].size());
  for (int i = r[2].size() - 1; i >= 0; i--)
    printf("%d ", r[2][i] + 1);
  for (int i: r[1])
    printf("%d ", i + 1);
  return 0;
}
