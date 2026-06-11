#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100005

//#define debug_printf printf
#define debug_printf(...) {}

int n;
int A[MAX_N];

int main()
{
  int i;
  pair<int, int> p[MAX_N+5];
  int ans = 0;

  scanf("%d", &n);
  for (i=1; i<=n; i++) {
    scanf("%d", &A[i]);
    p[i] = make_pair(A[i],i);
  }
  sort(p+1, p+n+1);

  for (i=1; i<=n; i++) {
    debug_printf("%d %d %d\n", i, p[i].first, p[i].second);
    if ((p[i].second % 2) != (i % 2)) {
      ans++;
    }
  }
  printf("%d\n", ans/2);

  return 0;
}
