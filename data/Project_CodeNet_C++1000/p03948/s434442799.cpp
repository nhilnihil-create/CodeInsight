#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (100000)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, T, as[MAX_N];
  scanf("%d %d", &N, &T);
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }

  // optimal move
  // max_rests[i] : max{as[i], ..., as[N - 1]}
  // incomes[i] : income per apple if we bought apples at i
  int max_rests[MAX_N], incomes[MAX_N], max_income = 0;
  max_rests[N - 1] = as[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    max_rests[i] = max(max_rests[i + 1], as[i]);
  }
  for (int i = 0; i < N; i++) {
    incomes[i] = max_rests[i] - as[i];
    max_income = max(max_income, incomes[i]);
  }

  // solve
  // answer is the number of cities where apples can be bought to achieve
  // the maximum income
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += incomes[i] == max_income;
  }
  printf("%d\n", ans);

  return 0;
}
