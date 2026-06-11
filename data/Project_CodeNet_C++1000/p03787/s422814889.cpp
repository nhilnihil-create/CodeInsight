#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

vector <int> V[MAX];
int bio[MAX], col[MAX];

int dfs(int x, int cl)
{
  if (bio[x]++) return col[x] == cl;
  col[x] = cl;
  int ret = 1;
  for (auto it : V[x]) ret &= dfs(it, 1^cl);
  return ret;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  ll rje = 0;
  int praz = 0;
  int br[2] = {0, 0};
  REP(i, n) {
    if (!bio[i]) {
      if (V[i].empty()) { praz++; continue; }
      int tmp = dfs(i, 0);
      br[tmp]++;
      rje += tmp + 1;
    }
  }

  rje += (ll) br[0] * (br[0] - 1) / 2 * 2;
  rje += (ll) br[1] * (br[1] - 1) / 2 * 4;
  rje += (ll) br[0] * br[1] * 2;
  rje += (ll) praz * (praz + 2*(n-praz));
  printf("%lld\n", rje);

  return 0;
}
