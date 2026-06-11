#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 4002
int n;
int a[200002],b[200002];
bool jud(int x)
{
	for(int i=1;i<2*n;i++)
	{
		if(a[i]<=x)b[i]=0;
		else b[i]=1;
	}
	if(b[n]==b[n-1]||b[n]==b[n+1])return b[n];
	bool flag=true;
	for(int i=1;i<2*n-1;i++)
	{
		if(b[i]==b[i+1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		return b[n]^(n%2==0);
	}
	int l=0,r=n*2;
	for(int i=n-1;i;i--)
	{
		if(b[i]==b[i+1])
		{
			l=i;break;
		}
	}
	for(int i=n+1;i<2*n;i++)
	{
		if(b[i]==b[i-1])
		{
			r=i;break;
		}
	}
	if(b[l]==b[r])return b[l];
	else return (n-l+1)<(r-n+1)?b[l]:b[r];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=100000000,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		//printf("%d ",mid);
		if(jud(mid))l=mid+1;
		else ans=mid,r=mid-1;
	}
	printf("%d\n",ans);
}
