#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[100005],n;
int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
void haowuliaokuaixiake(int f)
{
	int x=0,y=0;
	for (int i=1;i<=n;i++)
		if (a[i]&1) x++; else y++;
	if (y&1)
	{
		if (f==1) printf("First\n"); else printf("Second\n");
		return;
	}
	if (x>1)
	{
		if (f==1) printf("Second\n"); else printf("First\n");
		return;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==1)
		{
			if (f==1) printf("Second\n"); else printf("First\n");
			return;
		}
	for (int i=1;i<=n;i++)
		if (a[i]&1) a[i]--;
	int g=a[1];
	for (int i=2;i<=n;i++)
		g=gcd(g,a[i]);
	for (int i=1;i<=n;i++)
		a[i]/=g;
	haowuliaokuaixiake(-f);
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	haowuliaokuaixiake(1);
	return 0;
}