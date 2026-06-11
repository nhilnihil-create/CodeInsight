#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main()
{
	int ps,nw,ans=0,up,l,mo;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	nw=0,ps=1;
	for(int i=n-1;i>=1;i--)
	{
		nw++;
		if(nw>=a[i]){nw--,ps=i+1;break;}
	}
	l=0;
	for(int i=ps-1;i>=1;i--)
	{
		if(a[i]>nw)l++;
	}
	up=(a[ps]-nw)&1;
	l=(l&1)^1;
	if(up&&l)puts("Second");
	else puts("First");
}