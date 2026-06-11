#include <cstdio>
#include <map>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(it = c.begin(); it != c.end(); it++)

const int N_MAX = 100000;

typedef long long ll;

int H, W, N;
int a[N_MAX];
int b[N_MAX];

map<pair<int, int>, int> sqs;
int cnts[10];

void solve() {
  REP(k, N) {
    FOR(i, -2, 0) FOR(j, -2, 0) {
      int i2 = a[k] - 1 + i;
      int j2 = b[k] - 1 + j;
      if (i2 < 0 || i2 + 2 >= H || j2 < 0 || j2 + 2 >= W) continue;
      sqs[make_pair(i2, j2)]++;
    }
  }
  map<pair<int, int>, int>::iterator it;
  ITR(sqs, it) cnts[it->second]++;
  ll total = (ll) (H - 2) * (W - 2);
  FOR(k, 1, 9) total -= cnts[k];

  printf("%lld\n", total);
  FOR(k, 1, 9) printf("%d\n", cnts[k]);
}

void input() {
  scanf("%d%d%d", &H, &W, &N);
  REP(i, N) scanf("%d%d", a + i, b + i);
}

int main() {
  input();
  solve();
  return 0;
}
