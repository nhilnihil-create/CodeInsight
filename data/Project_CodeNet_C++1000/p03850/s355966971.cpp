#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long pre[111000],suf[111000],ans;
int a[110000],rr[111000],m,n,l,k,j;
char sg[1110000];
long long cmp(int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	else
	{
		return suf[r]-suf[l-1];
	}
}
int main()
{
	cin>>m;
	cin>>a[1];
	pre[1]=a[1];
	suf[1]=a[1];
	for(int x=1;x<m;x++)
	{
	scanf(" %c %d",&sg[x],&a[x+1]);
		if(sg[x]=='+')
		{
			pre[x+1]=pre[x]+a[x+1];
		}
		else
		{
			pre[x+1]=pre[x]-a[x+1];
		}
			suf[x+1]=suf[x]+a[x+1];
	}
	rr[m]=m;
	ans=pre[m];
	for(int x=m-1;x>=0;x--)
	{
		if(sg[x]=='+')
		{
			rr[x]=rr[x+1];
		}
		else
		{
			rr[x]=x;
		}
	}
	for(int x=1;x<m;x++)
	{
		if(sg[x]=='-')
		ans=max(ans,pre[x]-cmp(x+1,rr[x+1])+suf[m]-suf[rr[x+1]]);
	}
	printf("%lld\n",ans);
}