// https://atcoder.jp/contests/abc071/tasks/arc081_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const int A_I_MAX = 1e9;

int N;
int A[N_MAX];

vector<ll> ls;

void solve() {
  sort(A, A + N, greater<int>());
  int i = 0;
  while (i <= N - 2) {
    if (A[i] == A[i + 1]) {
      ls.push_back(A[i]);
      if (ls.size() >= 2) {
        printf("%lld\n", ls[0] * ls[1]);
        return;
      }
      i += 2;
    } else {
      i++;
    }
  }
  puts("0");
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
