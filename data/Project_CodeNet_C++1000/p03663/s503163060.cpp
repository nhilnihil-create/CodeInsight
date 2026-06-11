#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool get(ll x)
{
	printf("? %lld\n", x);
	fflush(stdout);
	char z;
	scanf(" %c", &z);
	return z == 'Y';
}
void answer(ll x)
{
	printf("! %lld\n", x);
	fflush(stdout);
	exit(0);
}
int main()
{
	ll now = 1;
	for (int i = 0; i < 11; i++)
	{
		if (!get(now))break;
		now *= 10;
	}
	if (now == 100000000000LL)
	{
		ll t = 1;
		for (int i = 0; i < 11;i++)
		{
			if (get(t * 10 - 1))answer(t);
			t *= 10;
		}
	}
	else
	{
		ll beg = now / 10 + 1, end = now - 1;
		for (;;)
		{
			if (beg == end)break;
			ll med = (beg + end) / 2;
			if (get(med * 10))end = med;
			else beg = med + 1;
		}
		answer(beg);
	}
}