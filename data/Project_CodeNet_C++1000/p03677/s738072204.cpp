#include <bits/stdc++.h>

using namespace std;

const int N_ = 100500;

int N, M;
int A[N_];

long long S[N_], T[N_];

void add(long long *arr, int s, int e, long long v) {
  arr[s] += v;
  arr[e+1] -= v;
}

int main() {
#ifdef IN_MY_COMPUTER
  freopen("e.in", "r", stdin);
#endif
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]), A[i] -= 1;

  for(int i = 2; i <= N; i++) {
    int a = A[i-1], b = A[i];

    int d = (b - a + M) % M;

    int p = (b - d + 1 + M) % M;
    
    if(p <= b) {
      add(T, 0, p-1, d);
      add(S, p, b, -1);
      add(T, p, b, b+1);
    }else {
      add(S, 0, b, -1);
      add(T, 0, b, b+1);
    }

    if(p <= b) {
      add(T, b+1, M-1, d);
    }else {
      add(T, b+1, p, d);

      add(S, p+1, M-1, -1);
      add(T, p+1, M-1, M+b+1);
    }
  }

  long long ans = 1e18;
  for(int i = 0; i < M; i++) {
    if(i > 0) {
      S[i] += S[i-1];
      T[i] += T[i-1];
    }
    ans = min(ans, S[i] * i + T[i]);
  }

  printf("%lld\n", ans);
  return 0;
}