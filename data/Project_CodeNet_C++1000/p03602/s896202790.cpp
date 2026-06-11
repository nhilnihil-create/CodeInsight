#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (300)
#define INF (100000000000000000L)

using namespace std;

long dp[MAX_N][MAX_N][MAX_N + 1];

int main(int argc, char *argv[]) {
  // read inputs
  long N, ass[MAX_N][MAX_N];
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    for (long j = 0; j < N; j++) {
      scanf("%ld", &ass[i][j]);
    }
  }

  // warshall-floyd
  // initialize
  for (long i = 0; i < N; i++) {
    for (long j = 0; j < N; j++) {
      dp[i][j][0] = ass[i][j];
    }
  }
  // calculate
  for (long k = 0; k < N; k++) {
    for (long i = 0; i < N; i++) {
      for (long j = 0; j < N; j++) {
        dp[i][j][k + 1] = min(dp[i][j][k], dp[i][k][k] + dp[k][j][k]);
      }
    }
  }
  // for (long i = 0; i < N; i++) {
  //   for (long j = 0; j < N; j++) {
  //     printf("%ld ", dp[i][j][N]);
  //   }
  //   printf("\n");
  // }
  // check that it matches ass
  for (long i = 0; i < N; i++) {
    for (long j = 0; j < N; j++) {
      if (dp[i][j][N] != ass[i][j]) {
        printf("-1\n");
        return 0;
      }
    }
  }

  // solve
  long ans = 0;
  for (long i = 0; i < N; i++) {
    for (long j = i + 1; j < N; j++) {
      long is_removable = 0;
      for (long k = 0; k < N; k++) {
        if (k != i && k != j && ass[i][j] == ass[i][k] + ass[k][j]) {
          is_removable = 1;
        }
      }
      if (!is_removable) {
        ans += ass[i][j];
      }
    }
  }
  printf("%ld\n", ans);

  return 0;
}
