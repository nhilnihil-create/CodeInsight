#include <iostream>
#define N 60
#define MOD 1000000007

int n; char s1[N], s2[N];

int main()
{
	scanf("%d", &n);
	scanf("%s%s", s1 + 1, s2 + 1);
	long long ans = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(i == 1 && s1[i] == s2[i])
			ans = (ans * 3) % MOD;
		else if(s1[i] == s2[i])
		{
			if(s1[i - 1] == s2[i - 1])
				ans = (ans * 2) % MOD;
		}
		else
		{
			if(i == 1)
				ans = (ans * 6) % MOD;
			else if(s1[i - 1] == s2[i - 1])
				ans = (ans * 2) % MOD;
			else if(s1[i] != s1[i - 1])
				ans = (ans * 3) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
