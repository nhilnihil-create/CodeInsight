#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<
#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define debug
//#define TRACE(x)

using namespace std;

typedef long long llint;

const int MAXN = 100010;

int n, m;
vector<int> e[MAXN];
int bio[100][100], cnt, k, vis[MAXN], col[MAXN];
llint sol;
bool bip;
int bcomp, ncomp, tot_comp;

void dfs(int x) {
  for (int y : e[x]) {
    if (col[y] == -1) {
      col[y] = col[x] ^ 1;
      dfs(y);
    }
    else if (col[x] == col[y])
      bip = false;
  }
}

// void dfs(int a, int b) {
//   bio[a][b] = 1;
//   for (int x : e[a])
//     for (int y : e[b])
//       if (!bio[x][y])
// 	dfs(x, y);
// }

int main(void) {
  scanf("%d %d",&n,&m);
  REP(i, m) {
    int u, v;
    scanf("%d %d",&u,&v);
    --u;
    --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  REP(i, n)
    if (e[i].empty())
      ++k;

  sol += k;
  sol += (llint)k * (k - 1);
  sol += 2 * (llint)k * (n - k);

  memset(col, -1, sizeof(col));
  REP(i, n) {
    if (e[i].empty()) continue;
    if (col[i] != -1) continue;

    bip = true;
    col[i] = 0;
    dfs(i);

    if (bip)
      ++bcomp;
    else
      ++ncomp;
    ++tot_comp;
  }

  //TRACE(sol _ bcomp _ ncomp);

  sol += (llint)tot_comp * tot_comp;
  sol += (llint)bcomp * bcomp;

  cout << sol << endl;
  
  return 0;
}
