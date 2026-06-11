#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;
const int MAX_N = 100005;

int N, M, fa1[MAX_N], fa2[MAX_N << 1], ok[MAX_N], sz[MAX_N];
bool vis[MAX_N];

int find(int x, int *fa) {
  return fa[x] == x ? x : fa[x] = find(fa[x], fa);
}

bool merge1(int x, int y) {
  x = find(x, fa2), y = find(y, fa2);
  if (x == y) return false;
  fa2[x] = y;
  return true;
}

void merge2(int x, int y) {
  x = find(x, fa1), y = find(y, fa1);
  if (x == y) return;
  fa1[x] = y, sz[y] += sz[x], ok[y] &= ok[x];
}

int main() {
  scanf("%d%d", &N, &M);
  
  for (int i = 1; i <= N; ++i) {
    ok[i] = 1, sz[i] = 1;
    fa1[i] = fa2[i] = i, fa2[i + N] = i + N;
  }
  
  for (int i = 1, u, v; i <= M; ++i) {
    scanf("%d%d", &u, &v);
    merge2(u, v);
    if (u == v || find(u, fa2) == find(v, fa2) || find(u + N, fa2) == find(v + N, fa2)) {
      ok[find(u, fa1)] = 0;
    } else {
      merge1(u, v + N);
      merge1(u + N, v);
    }
  }

  i64 num1 = 0, num2 = 0, num3 = 0;
  
  for (int i = 1; i <= N; ++i) {
    int x = find(i, fa1);
    if (vis[x]) continue;
    
    vis[x] = 1;
    if (sz[x] == 1 && ok[x]) num1++;
    else if (ok[x]) num2++;
    else num3++;
  }

  i64 res = num1 * N * 2 - num1 * num1;
  res += num2 * num2 * 2 + num3 * num2 * 2 + num3 * num3;

  printf("%lld\n", res);
  
  return 0;
}
