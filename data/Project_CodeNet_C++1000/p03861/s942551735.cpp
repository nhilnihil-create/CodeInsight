#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll a, b, x;
	while(scanf("%lld %lld %lld", &a, &b, &x) != EOF)
	{
		ll count = 0;
		count += (b/x) - (a/x);
		if (a%x==0)
			count++;
		printf("%lld\n", count);
	}
	return 0;
}
