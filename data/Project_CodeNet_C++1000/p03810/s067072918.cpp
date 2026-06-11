#include <bits/stdc++.h>
using namespace std;

int n,a[100010];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

bool solve()
{
	int s=0,mn=1<<30;
	for (int i=1; i<=n; i++)
		s+=(a[i]-1)&1,mn=min(mn,a[i]);
	if (s&1)  return 1;
	else  if ((n-s>1)||(mn==1))  return 0;
	else
		{
			int g=0;
			for (int i=1; i<=n; i++)  g=gcd(g,a[i]-=a[i]&1);
			for (int i=1; i<=n; i++)  a[i]/=g;
			return !solve();
		}
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	puts(solve()?"First":"Second");
}

int main()
{
	work();
	return 0;
}
