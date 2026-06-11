// https://atcoder.jp/contests/abc062/tasks/arc074_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const int A_I_MAX = 1e9;
const ll INF = 1e15;

int N;
int a[N_MAX * 3];

ll L[N_MAX + 1];
ll R[N_MAX + 1];

void solve() {
  priority_queue<int, vector<int>, greater<int> > lq;
  REP(i, N) {
    int la = a[i];
    L[0] += la;
    lq.push(la);
  }
  REP(i, N) {
    int li = lq.top();
    int la = a[N + i];
    if (la > li) {
      L[i + 1] = L[i] - li + la;
      lq.pop(); lq.push(la);
    } else {
      L[i + 1] = L[i];
    }
  }
  priority_queue<int, vector<int> > rq;
  for(int i = N * 3 - 1; i >= N * 2; i--) {
    int ra = a[i];
    R[N] += ra;
    rq.push(ra);
  }
  for (int i = N - 1; i >= 0; i--) {
    int rx = rq.top();
    int ra = a[N + i];
    if (ra < rx) {
      R[i] = R[i + 1] - rx + ra;
      rq.pop(); rq.push(ra);
    } else {
      R[i] = R[i + 1];
    }
  }
  // DUMP(L, N + 1);
  // DUMP(R, N + 1);
  ll ans = -INF;
  REP(i, N + 1) ans = max(ans, L[i] - R[i]);
  printf("%lld\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N * 3) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
