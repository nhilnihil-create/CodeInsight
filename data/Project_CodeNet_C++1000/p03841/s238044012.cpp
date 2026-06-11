#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 505;

typedef pair<int, int> pii;

int A[MAX_N * MAX_N], pos[MAX_N][MAX_N], cnt[MAX_N], N;
pii X[MAX_N];

int main() {
  scanf("%d", &N);
  for (int i = 1, temp; i <= N; ++i) {
    scanf("%d", &temp);
    X[i] = make_pair(temp, i);
    A[temp] = i;
  }
  
  sort(X + 1, X + N + 1);

  int tot = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j < X[i].second; ++j) {
      if (A[tot + 1]) {
	tot++, j--;
	continue;
      }
      A[++tot] = X[i].second;
    }
  }
  
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N - X[i].second; ++j) {
      if (A[tot + 1]) {
	tot++, j--;
	continue;
      }
      A[++tot] = X[i].second;
    }
  }

  tot = N * N;
  for (int i = 1; i <= tot; ++i) 
    pos[A[i]][++cnt[A[i]]] = i;
  for (int i = 1; i <= N; ++i)
    if (pos[X[i].second][X[i].second] != X[i].first) {
      puts("No");
      return 0;
    }
  puts("Yes");
  for (int i = 1; i <= tot; ++i)
    printf("%d ", A[i]);
  puts("");
  return 0;
}
