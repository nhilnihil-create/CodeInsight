#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for(register int i = l; i <= r; i++)
#define ford(i, r, l) for(register int i = r; i >= l; i--)

int N, A[100005];

int main() {
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
  scanf("%d", &N);
  foru(i, 1, N) scanf("%d", &A[i]);
  int now_len = 0, Ans = 0, type = -1;
  now_len++;
  foru(i, 2, N) {
    if(now_len == 1) {
      now_len++;
      if (A[i] == A[i - 1])
        type = -1;
      else
        type = A[i] > A[i - 1];
      continue;
    }
    if(A[i] == A[i - 1]) {
      now_len++;
      continue;
    }
    if(type < 0) {
      now_len++;
      type = A[i] > A[i - 1];
      continue;
    }
    if(A[i] > A[i - 1] && type) {
      now_len++;
      continue;
    }
    if (A[i] < A[i - 1] && !type) {
      now_len++;
      continue;
    }
    Ans++, now_len = 1;
  }
  printf("%d\n", Ans + 1);
  return 0;
}
