#include <cstdio>

constexpr long long MOD = 1000000007;

int main()
{
  int n;
  char s[2][53];
  scanf("%d%s%s", &n, s[0], s[1]);
  long long ans = 1;
  int last = 0;
  for (int i = 0; i < n;)
  {
    if (s[0][i] == s[1][i])
    {
      long long p;
      if (last == 0) p = 3;
      else if (last == 1) p = 2;
      else p = 1;
      ans = ans * p % MOD;
      ++i;
      last = 1;
    }
    else
    {
      long long p;
      if (last == 0) p = 3 * 2;
      else if (last == 1) p = 2 * 1;
      else p = 2 + 1;
      ans = ans * p % MOD;
      i += 2;
      last = 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}