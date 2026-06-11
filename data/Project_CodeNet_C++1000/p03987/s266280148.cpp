#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

const int maxn = 2e5 + 5;
int N, A[maxn], L[maxn], R[maxn];
int sta[maxn], top;

int main() {
  scanf("%d", &N);
  foru(i, 1, N) scanf("%d", &A[i]);
  top = 0;
  foru(i, 1, N) {
    while (top && A[sta[top]] > A[i]) top--;
    L[i] = sta[top], sta[++top] = i;
  }
  sta[top = 0] = N + 1;
  ford(i, N, 1) {
    while (top && A[sta[top]] > A[i]) top--;
    R[i] = sta[top], sta[++top] = i;
  }
  long long Ans = 0;
  foru(i, 1, N) {
    long long len_l = i - L[i];
    long long len_r = R[i] - i;
    Ans += len_l * len_r * A[i];
  }
  printf("%lld\n", Ans);
  return 0;
}
