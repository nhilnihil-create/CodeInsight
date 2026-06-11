#include<cstdio>
#include<iostream>
using namespace std;
int a[100010];
int n;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
bool dg()
{
	long long sum=0;
	bool ex=0;
	int num=0;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i]-1;
		if (a[i]==1) ex=1;
		if (a[i]&1) num++;
	}
	if (ex) return sum%2;
	if ((n-num)%2) return 1;
	if (num==1)
	{
		int g=0;
		for (int i=1;i<=n;i++)
			if (a[i]&1) a[i]--;
		for (int i=1;i<=n;i++)
			g=gcd(g,a[i]);
		for (int i=1;i<=n;i++)
			a[i]/=g;
		return dg()^1;
	}
	return 0;
		
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (dg()) printf("First");
		else printf("Second");
}