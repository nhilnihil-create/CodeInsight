#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

const int maxn=1e5+10;

int n,a[maxn];

bool solve()
{
	int i;
	bool flag=0;
	for (i=1;i<=n;i++) flag|=a[i]==1;
	if (flag)
	{
		for (i=1;i<=n;i++) flag^=(a[i]-1)&1;
		return flag^1;
	}
	int odd=0,even=0;
	for (i=1;i<=n;i++) odd+=a[i]&1;
	even=n-odd;
	if (!even) return 0;
	if (even&1) return 1;
	if (odd>1) return 0;
	for (i=1;i<=n;i++) a[i]-=a[i]&1;
	int g=a[1];
	for (i=2;i<=n;i++) g=gcd(g,a[i]);
	for (i=1;i<=n;i++) a[i]/=g;
	return solve()^1;
}

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	puts(solve()?"First":"Second");
}
