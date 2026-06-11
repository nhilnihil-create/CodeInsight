#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')

//------------------------------------------------------------------------------
#define SZ      (sz * 2 - 1)
#define LF(i)   (i + sz - 1)
#define PA(k)   ((k - 1) / 2)
#define LC(k)   (k * 2 + 1)
#define RC(k)   (k * 2 + 2)
#define M(l,r)  ((l + r) / 2)

const int ST_SIZE = 1 << 18;    // N_MAX * 2 - 1

int sz;
int dat[ST_SIZE];

void rmq_init(int n) {
  sz = 1;
  while (sz < n) sz <<= 1;
}

int query(int i) {
  int k = LF(i);
  int ret = dat[k];
  while (k > 0) {
    k = PA(k);
    ret += dat[k];
  }
  return ret;
}

void add_sub(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return;
  if (a <= l && r <= b) dat[k]++;
  else {
    add_sub(a, b, LC(k), l, M(l, r));
    add_sub(a, b, RC(k), M(l, r), r);
  }
}

void add(int a, int b) {
  add_sub(a, b, 0, 0, sz);
}

//------------------------------------------------------------------------------
const int N_MAX = 300000;
const int M_MAX = 100000;

struct rng { int w, l, r; };
int N, M;
rng a[N_MAX];

bool compare_w(const rng& r1, const rng& r2) {
  return r1.w < r2.w;
}

void solve() {
  sort(a, a + N, compare_w);
  rmq_init(M + 1);
  int i = 0;
  FOR(d, 1, M) {
    while (i < N && a[i].w < d) {
      // printf("w: %d, l:%d, r: %d\n", a[i].w, a[i].l, a[i].r);
      add(a[i].l, a[i].r + 1);
      // DUMP(dat, SZ);
      i++;
    }
    int ans = N - i;
    if (i > 0) {
      for(int e = d; e <= M; e += d) {
        ans += query(e);
      }
    }
    printf("%d\n", ans);
  }
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    int l, r, w;
    scanf("%d%d", &l, &r);
    a[i] = { r - l + 1, l, r };
  }
}

int main() {
  input();
  solve();
  return 0;
}
