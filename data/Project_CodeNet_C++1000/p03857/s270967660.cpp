#include <cstdio>
#include <map>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

//------------------------------------------------------------------------------
const int UF_SIZE = 200000;

struct UF {
  int par[UF_SIZE];
  int rnk[UF_SIZE];
  void init(int n) {
    REP(i, n) {
      par[i] = i;
      rnk[i] = 0;
    }
  }
  int find(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

//------------------------------------------------------------------------------
const int K_MAX = 100000;
const int L_MAX = 100000;

typedef pair<int, int> P;

int N, K, L;
int p[K_MAX];
int q[K_MAX];
int r[L_MAX];
int s[L_MAX];

UF road;
UF rail;
map<P, int> cnts;

void solve() {
  road.init(N);
  REP(i, K) road.unite(p[i] - 1, q[i] - 1);

  rail.init(N);
  REP(i, L) rail.unite(r[i] - 1, s[i] - 1);

  REP(i, N) {
    cnts[P(road.find(i), rail.find(i))]++;
  }
  REP(i, N) printf("%d%c",
    cnts[P(road.find(i), rail.find(i))],
    i + 1 == N ? '\n' : ' '
  );
}

void input() {
  scanf("%d%d%d", &N, &K, &L);
  REP(i, K) scanf("%d%d", p + i, q + i);
  REP(i, L) scanf("%d%d", r + i, s + i);
}

int main() {
  input();
  solve();
  return 0;
}
