#include <bits/stdc++.h>

using namespace std;

int N, ans[505 * 505];

struct XX {
  int pos, id, L, R;
  bool operator<(const XX& o) const { return pos < o.pos; }
} X[505];

int main() {
//  freopen("a.in", "r", stdin);
//  freopen("a.out", "w", stdout);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &X[i].pos);
    ans[X[i].pos] = i;
    X[i].id = i;
    X[i].L = i - 1;
    X[i].R = N - i;
  }
  sort(X + 1, X + N + 1);
  int tot = N * N;
  for (int i = 1; i <= tot; i++) {
    if (ans[i]) continue;
    for (int j = 1; j <= N; j++) {
      if (X[j].L > 0 && X[j].pos >= i) {
        ans[i] = X[j].id;
        X[j].L--;
        break;
      }
    }
  }
  for (int i = tot; i >= 1; i--) {
    if (ans[i]) continue;
    for (int j = N; j >= 1; j--) {
      if (X[j].R > 0 && X[j].pos <= i) {
        ans[i] = X[j].id;
        X[j].R--;
        break;
      }
    }
  }
  bool flag = true;
  for (int i = 1; i <= tot; i++)
    if (!ans[i]) flag = false;
  if (!flag) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], " \n"[i == tot]);
  return 0;
}
