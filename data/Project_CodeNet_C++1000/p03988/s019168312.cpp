#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

int N, a[102], D[102], cnt[102];
#define Error return puts("Impossible"), 0

int main() {
  scanf("%d", &N);
  foru(i, 1, N) scanf("%d", &a[i]);
  sort(a + 1, a + N + 1);
  if (a[1] != (a[N] + 1) / 2) Error;
  foru(i, 1, N) cnt[a[i]]++;
  ford(i, a[N], a[1] + 1) if (cnt[i] < 2) Error;
  if (cnt[a[1]] != (a[N] % 2) + 1) Error;
  puts("Possible");
  return 0;
}
