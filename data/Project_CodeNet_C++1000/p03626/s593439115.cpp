// https://atcoder.jp/contests/abc071/tasks/arc081_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 52;
const int MOD = 1000000007;

const int INITIAL = 0;
const int VERTICAL = 1;
const int HORIZONTAL = 2;

const int coef[3][3] = { {0, 3, 6}, {0, 2, 2}, {0, 1, 3} };

int N;
char S[2][N_MAX + 1];

vector<int> a;

void solve() {
  a.push_back(INITIAL);
  bool skip = false;
  REP(i, N) {
    if (skip) {
      skip = false;
    } else if (S[0][i] == S[1][i]) {
      a.push_back(VERTICAL);
    } else {
      a.push_back(HORIZONTAL);
      skip = true;
    }
  }
  ll ans = 1;
  REP(i, a.size() - 1) {
    ans = ans * coef[a[i]][a[i + 1]] % MOD;
  }
  printf("%lld\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, 2) scanf("%s", S[i]);
}

int main() {
  input();
  solve();
  return 0;
}
