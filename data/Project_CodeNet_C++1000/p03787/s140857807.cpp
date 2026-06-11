#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5;

int n, m;
int par[MAXN], comp[MAXN], sz[MAXN];

int f(int x) {
  if(par[x] == x) return x;
  return par[x] = f(par[x]);
}

void unija(int x, int y) {
  x = f(x); y = f(y);
  if(x == y) return;

  sz[y] += sz[x];
  par[x] = y;
}

vector<int> ee, e[MAXN];

int c[MAXN];

bool bipartite(int x, int y) {
  if(c[x]) {
    if(c[x] != y) return false;
    return true;
  }

  c[x] = y;

  bool ret = true;
  for(auto w: e[x]) {
    ret &= bipartite(w, 3 - y);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;

  REP(i, n) {
    par[i] = i;
    sz[i] = 1;
  }

  REP(i, m) {
    int x, y; cin >> x >> y;
    x --; y --;
    e[x].push_back(y);
    e[y].push_back(x);
    ee.push_back(x);
    unija(x, y);
  }

  for(auto &x: ee) {
    comp[f(x)] ++;
  }

  ll sol = 0;
  int pola = 0, cijela = 0, prazni = 0;

  REP(i, n) {
    if(f(i) != i) continue;

    if(sz[i] > 1) {
      sol ++;
      if(bipartite(i, 1)) {
        sol ++;
        sol += cijela * 2;
        sol += pola * 4;
        pola ++;
      }
      else {
        sol += cijela * 2;
        sol += pola * 2;
        cijela ++;
      }
    }
    else {
      sol += n * 2 - 1;
      sol -= prazni * 2;
      prazni ++;
    }
  }

  cout << sol;
}
