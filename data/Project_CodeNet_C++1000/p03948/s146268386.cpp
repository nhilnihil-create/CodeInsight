#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int INF = 1000000000;
const int N_MAX = 100000;

int N, T;
int A[N_MAX];

void solve() {
  int am = INF;
  int diff = -1;
  int ans = 0;
  REP(i, N) {
    if (A[i] < am) {
      am = A[i];
    } else if (A[i] - am == diff) {
      ans++;
    } else if (A[i] - am > diff) {
      diff = A[i] - am;
      ans = 1;
    }
  }
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &T);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
