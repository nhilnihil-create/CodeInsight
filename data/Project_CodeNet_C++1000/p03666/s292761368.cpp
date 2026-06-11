#include <cstdio>

int main()
{
  long long n, a, b, c, d;
  scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
  for (long long i = 0; i <= n - 1; ++i)
  {
    long long s = a + i * c;
    long long t = a + i * d;
    long long v = b + (n - 1 - i) * c;
    long long w = b + (n - 1 - i) * d;
    if (w < s || v > t) continue;
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}