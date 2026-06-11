#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

typedef long long ll;
int N, A[1000005], hd, tl;
ll Ans;

int main() {
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
  scanf("%d", &N), hd = 1, tl = (N *= 3);
  foru(i, 1, N) scanf("%d", &A[i]);
  sort(A + 1, A + N + 1);
  while (tl - hd + 1 >= 3) Ans += A[(tl -= 2) + 1], hd++;
  printf("%lld\n", Ans);
  return 0;
}
