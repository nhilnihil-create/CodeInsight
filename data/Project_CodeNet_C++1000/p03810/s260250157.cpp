#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
bool solve()
{
	int sum_odd=0,sum_even=0;
	for (int i=1;i<=n;i++)
	{
		sum_odd+=a[i]&1;
		sum_even+=(a[i]&1)^1;
	}
	if (sum_even&1) return 1;
	if (sum_odd==1)
	{
		int t=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]&1)
			{
				if (a[i]==1) return 0;
				a[i]--;
			}
			t=__gcd(t,a[i]);
		}
		for (int i=1;i<=n;i++)
			a[i]/=t;
		return solve()^1;
	}
	else return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	puts(solve()?"First":"Second");
}