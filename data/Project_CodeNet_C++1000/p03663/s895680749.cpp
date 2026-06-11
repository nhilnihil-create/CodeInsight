#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool guess(ll x)
{
	if (x == 0) return 1;
	printf("? %lld\n", x);
	fflush(stdout);
	char ch = getchar();
	while (ch != 'Y' && ch != 'N') ch = getchar();
	return ch == 'Y';
}
void confirm(ll x)
{ 
	printf("! %lld\n", x);
	fflush(stdout);
	exit(0);
}

int main()
{
	ll n, l, r, mid;
	bool flag = 0;
	n = 1;
	for (int k = 1; k <= 10; ++k)
	{
		if (!guess(n))
		{
			flag = 1;
			n /= 10;
			break;
		}
		else n *= 10ll;
	}
	if (!flag)
	{
		n = 9;
		while (1)
		{
			if (guess(n))
				confirm(n / 10 + 1);
			n = n * 10 + 9;
		}
	}
	l = n;
	r = n * 10 - 1;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (guess(10ll * mid + 1))
			r = mid;
		else
			l = mid + 1;
	}
	confirm(l);
	return 0;
}