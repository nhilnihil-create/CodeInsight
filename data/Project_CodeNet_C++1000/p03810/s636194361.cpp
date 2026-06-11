#include <cstdio>
#include <algorithm>
#include <numeric>
int N, a[100001];
int gcd(int x, int y)
{
	int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
bool F()
{
	auto is_odd = [] (int x) { return x & 1; };
	int odd = std::count_if(a + 1, a + N + 1, is_odd), even = N - odd;
	if (even & 1)
		return true;
	if (odd == 1)
	{
		int &D = *std::find_if(a + 1, a + N + 1, is_odd);
		if (D == 1)
			return false;
		D--;
		int G = std::accumulate(a + 1, a + N + 1, 0, gcd);
		std::for_each(a + 1, a + N + 1, [G] (int &x) { x /= G; });
		return !F();
	}
	return false;
}
int main()
{
	scanf("%d", &N);
	std::for_each(a + 1, a + N + 1, [] (int &x) { scanf("%d", &x); });
	puts(F() ? "First" : "Second");
	return 0;
}
