#include<cstdio>
#define ll long long
using namespace std;
ll a[51];
int main()
{
	ll n;
	scanf("%lld", &n);
	puts("50");
	for (int i = 0; i < 50; i++)
	{
		ll gap = n/50 + i;
		a[i] = gap;
	}
	ll ch = n % 50;
	for (int i = 49; i >= 0; i--)
	{
		if (ch)
		{
			a[i]++;
			ch--;
		}
	}
	for (int i = 0; i < 50; i++)
		printf("%lld ", a[i]);
}