#include <stdio.h>
long long p = 1000000007;
long long y;
int n, a, f;
int x[100000];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a);
		x[a]++;
	}
	if (n % 2) 
	{
		if (x[0] != 1)f = 1;
		for (int i = 1; i <= n / 2; i++) 
		{
			if (x[i * 2] != 2)f = 1;
		}
	}
	else 
	{
		for (int i = 0; i < n / 2; i++)
		{
			if (x[i * 2 + 1] != 2)f = 1;
		}
	}
	if (f)printf("0\n");
	else
	{
		y = 1;
		for (int i = 0; i < n / 2; i++) 
		{
			y *= 2;
			y %= p;
		}
		printf("%lld\n", y);
	}
}
