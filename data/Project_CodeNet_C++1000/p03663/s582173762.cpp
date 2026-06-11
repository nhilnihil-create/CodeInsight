#include <cstdio>
typedef long long ll;
char str[15]; 
inline bool query(ll x)
{
	printf("? %lld\n", x);
	fflush(stdout); 
	scanf("%s", str); 
	return str[0] == 'Y'; 
}
int main()
{
	ll x = 1e9, ans; 
	while (!query(x))
		x /= 10; 
	if (x == 1e9)
	{
		ans = 1; 
		while (!query(ans + 1))
			ans *= 10; 
	}
	else
	{
		int l = x, r = x * 10 - 1; 
		while (l <= r)
		{
			int m = l + r >> 1; 
			if (query((ll)m * 10))
			{
				ans = m; 
				r = m - 1; 
			}
			else
				l = m + 1; 
		}
	}
	printf("! %lld\n", ans);
	return 0; 
}
