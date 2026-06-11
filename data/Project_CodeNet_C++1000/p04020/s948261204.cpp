#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

typedef long long ll;
const int maxn = 1e6 + 5;
int A[maxn], N, Add;
ll Ans;

int main() {
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);
  scanf("%d", &N);
  foru(i, 1, N) scanf("%d", &A[i]);
  foru(i, 1, N) {
    Ans += A[i] >> 1, A[i] &= 1;
    if (A[i] && A[i + 1]) Ans++, A[i]--, A[i + 1]--;
  }
  printf("%lld\n", Ans);
  return 0;
}
