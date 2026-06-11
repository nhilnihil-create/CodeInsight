#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

int N;
int x[MAXN];
int suff[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", x + i);
}

void mn(int &a, int b) {
  a = min(a, b);
}

int solve() {
  memset(suff, INF, sizeof suff);
  suff[N] = N;
  for (int i = 0; i < N; i++)  
    if (x[i] <= 2 * i)
      mn(suff[(2 * i - x[i]) / 2], i);
  
  int sol = 1;
  for (int i = N - 1; i >= 0; i--) {
    suff[i] = min(suff[i], suff[i + 1]);
    sol = (long long)sol * (min(suff[i] + 1, N) - i) % MOD;
  }
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}