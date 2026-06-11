// https://atcoder.jp/contests/abc069/tasks/arc080_a

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const int A_I_MAX = 1e9;

int N;
int a[N_MAX];

void solve() {
  int c1 = 0;
  int c4 = 0;
  REP(i, N) {
    if (a[i] % 2 > 0) c1++;
    if (a[i] % 4 == 0) c4++;
  }
  bool cond = c1 <= c4 || c4 == N / 2;
  puts(cond ? "Yes" : "No");
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
