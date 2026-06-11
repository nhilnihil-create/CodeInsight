#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int mod = 1000000007;
bool ok[1010];
long long a[1010];

void f(int x)
{
	int n, i;
	n = x;
	i = 0;
	while(n > i)
	{
		i++;
		if (ok[i])
		{
			while (x % i == 0)
			{
				x /= i;
				a[i]++;
			}
		}
	}
}

signed main(void)
{
	int n;
	long long ans;

	cin >> n;
	rep(i, 1010) {ok[i] = true; a[i] = 0;}
	ok[0] = ok [1] = false;
	for (int i = 2; i < sqrt(n); i++) 
	{
		if (ok[i])
		{
			for (int j = 0; i * (j + 2) < n; j++)
			{	
				ok[i * (j + 2)] = false;
			}
		}
	}
	for (int i = n; i > 0; i--) f(i);
	ans = 1;
	rep(i, n + 1)
	{
		if (a[i])
		{
			ans *= a[i] + 1;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
