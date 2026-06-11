#include <cstdio>
#include <algorithm>

long long m[100000];
long long t[100000];
long long a[100000];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld", t + i);
    if (i == 0 || t[i] == 1 || t[i] != t[i - 1]) m[i] = t[i];
  }
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld", a + i);
  }
  for (int i = n - 1; i >= 0; --i)
  {
    if (i == n - 1 || a[i] == 1 || a[i] != a[i + 1])
    {
      if (m[i] == 0)
      {
        m[i] = a[i];
      }
    }
    if (m[i] == 0) continue;
    if (m[i] > a[i])
    {
      puts("0");
      return 0;
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i)
  {
    if (m[i] != 0) continue;
    ans = ans * std::min(t[i], a[i]) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}