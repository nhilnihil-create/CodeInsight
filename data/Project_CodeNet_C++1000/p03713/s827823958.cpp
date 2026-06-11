#include <cstdio>
#include <algorithm>

long long cnt(long long a, long long b)
{
  long long ans = a * b;
  for (int i = 1; i < a; ++i)
  {
    long long top = i * b;
    long long left = (a - i) * (b / 2);
    long long right = a * b - top - left;
    long long dif = std::max(top, std::max(left, right)) - std::min(top, std::min(left, right));
    if (ans > dif) ans = dif;
  }
  return ans;
}

int main()
{
  long long h, w;
  scanf("%lld%lld", &h, &w);
  
  if (h % 3 == 0 || w % 3 == 0)
  {
    puts("0");
    return 0;
  }
  
  printf("%lld\n", std::min(std::min(h, w), std::min(cnt(h, w), cnt(w, h))));
  return 0;
}