#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  long long max = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i)
  {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if (max < a)
    {
      max = a;
      ans = a + b;
    }
  }
  printf("%lld\n", ans);
  return 0;
}