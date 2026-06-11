#include <cstdio>

const int MaxV = 200000;

int N, V;
int A[MaxV + 5];

void init() {
  scanf("%d", &N);
  V = 2 * N - 1;
  for (int i = 1; i <= V; ++i)
    scanf("%d", &A[i]);
}

inline int check(int mid) {
  static int b[MaxV + 5];
  for (int i = 1; i <= V; ++i)
    if (A[i] >= mid) b[i] = 1;
    else b[i] = 0;
  static int pre[MaxV + 5], nxt[MaxV + 5];
  pre[1] = 1;
  for (int i = 2; i <= V; ++i)
    if (b[i] == b[i - 1]) pre[i] = pre[i - 1];
    else pre[i] = i;
  nxt[V] = V;
  for (int i = V - 1; i >= 1; --i)
    if (b[i] == b[i + 1]) nxt[i] = nxt[i + 1];
    else nxt[i] = i;
  if (pre[N] != N || nxt[N] != N) return b[N];
  int lpart = 0, rpart = V + 1;
  for (int i = 1; i < N; ++i) if (pre[i] != i) lpart = i;
  for (int i = V; i > N; --i) if (nxt[i] != i) rpart = i;
  if (lpart == 0 && rpart == V + 1) return b[1];
  else if (lpart == 0) return b[rpart];
  else if (rpart == V + 1) return b[lpart];
  else if (b[lpart] == b[rpart]) return b[lpart];
  else if (N - lpart < rpart - N) return b[lpart];
  else return b[rpart];
}

void solve() {
  int lbound = 1, rbound = V, ans = 0;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (check(mid) == 1) {
      ans = mid;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}