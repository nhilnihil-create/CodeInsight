#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],n,m;
bool check(int mid)
{
	int mi=1e9,j=-1;
	for(int i=m-1;i>=1;i--)
	{
		int a1=a[i]>=mid,a2=a[i+1]>=mid;
		if(a1==a2)
		{
			mi=m-i-1;
			j=a1;
			break;
		}
	}
	for(int i=m;i<n;i++)
	{
		int a1=a[i]>=mid,a2=a[i+1]>=mid;
		if(a1==a2)
		{
			if(mi>i-m)
			{
				mi=i-m;
				j=a1;
			}
			break;
		}
	}
	if(j==-1)return a[1]>=mid;
	else return j;
}
int main()
{
//	freopen("night.in","r",stdin);
//	freopen("night.out","w",stdout);
	int l=2e9,r=0;
	scanf("%d",&m);
	n=m*2-1;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),l=min(l,a[i]),r=max(a[i],r);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	return 0;
}