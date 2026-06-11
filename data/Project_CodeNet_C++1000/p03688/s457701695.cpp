#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 1;

int A[MN];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  sort(A, A+N);
  if (A[0] == A[N-1]) {
    if (A[0] == N-1) {
      puts("Yes");
    }
    else if (A[0] * 2 <= N) {
      puts("Yes");
    }
    else {
      puts("No");
    }
  }
  else if (A[0] + 1 == A[N-1]) {
    int n = 0;
    while(A[n] == A[0]) n++;
    // A[0] n,  A[0]+1 * N-n
    if (A[N-1] - n >= 1 && (A[N-1] - n) * 2 <= N-n) {
      puts("Yes");
    }
    else {
      puts("No");
    }
  }
  else {
    puts("No");
  }
  return 0;
}
