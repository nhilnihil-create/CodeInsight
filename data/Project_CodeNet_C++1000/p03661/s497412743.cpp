#include <cstdio>

#define abs(a) ((a) < 0 ? -(a) : (a))

int main()
{
  int n;
  scanf("%d", &n);
  long long a[200001] = {0};
  for (int i = 1; i <= n; ++i)
  {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }
  long long min = 1e18;
  for (int i = 1; i <= n - 1; ++i)
  {
    if (min > abs(a[n] - 2 * a[i]))
    {
      min = abs(a[n] - 2 * a[i]);
    }
  }
  printf("%lld\n", min);
  return 0;
}
