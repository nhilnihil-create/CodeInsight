#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

template<typename T, unsigned long long N, T M>
struct combination
{
	T array[(N + 1) * (N + 2) / 2];

	constexpr combination() : array()
	{
		array[0] = 1;
		for (unsigned long long i = 1; i <= N; ++i)
		{
			const auto first = i * (i + 1) / 2;
			const auto last = first + i;
			array[first] = array[last] = 1;
			const auto *p = &array[(i - 1) * i / 2];
			for (auto j = 1; j < i; ++j)
			{
				array[first + j] = (*p + *(p + 1)) % M;
	            ++p;
			}
		}
	}
	constexpr T C(T n, T r)
	{
		if (n < 0 || r < 0 || r > n) return 0;
		return array[n * (n + 1) / 2 + r];
	}
};

combination<long long, 100, (long long)1e18> comb;

int main()
{
  long long n, a, b;
  scanf("%lld%lld%lld", &n, &a, &b);
  
  long long v[50];
  for (long long i = 0; i < n; ++i)
  {
    scanf("%lld", v + i);
  }
  std::sort(v, v + n, std::greater<long long>());
  long long l, r;
  for (l = 0; l < n; ++l)
  {
    if (v[l] == v[a - 1])
    {
      r = l;
      while (v[r] == v[a - 1] && r < n) ++r;
      break;
    }
  }
  long long ans = 0;
  if (l == 0)
  {
    for (long long i = a; i <= b; ++i)
    {
      ans += comb.C(r, i);
    }
    printf("%.12f\n", double(v[0]));
  }
  else
  {
    ans = comb.C(r - l, a - l);
    printf("%.12f\n", std::accumulate(v, v + a, 0LL) / double(a));
  }
  printf("%lld\n", ans);
  return 0;
}