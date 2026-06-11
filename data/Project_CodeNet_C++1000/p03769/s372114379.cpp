#include <cstdio>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

typedef long long ll;

ll N;

void solve() {
  N++;
  vector<int> vs;
  int k = 0;
  ll n = N;
  while (n > 1) {
    vs.push_back(++k);
    n >>= 1;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (N >> i & 1) {
      vs.insert(vs.begin() + i, ++k);
    }
  }
  printf("%d\n", k * 2);
  REP(i, k)  printf("%d ", vs[i]);
  FOR(i, 1, k)  printf("%d%c", i, i == k ? '\n' : ' ');
}

void input() {
  scanf("%lld", &N);
}

int main() {
  input();
  solve();
  return 0;
}
