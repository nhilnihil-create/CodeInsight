#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	if (n == 1)
	{
		if (a == b)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	if (a > b)
	{
		printf("0\n");
		return 0;
	}
	printf("%lld\n", (b * (n - 1) + a) - (a * (n - 1) + b) + 1);
	return 0;
}