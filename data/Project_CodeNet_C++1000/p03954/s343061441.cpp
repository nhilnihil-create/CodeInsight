#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s;
int a[200200];
int t[200200];
bool check(int x)
{
	for(int i=1;i<=s;++i)
		if(a[i]<=x)t[i]=0;
		else t[i]=1;
	int fl=0;
	int d0=s,d1=s;
	for(int i=1;i<=s;++i)
	{
		int c=0,dis=abs(n-i);
		for(;t[i+c+1]==t[i]&&i+c+1<=s;c++)dis=min(dis,abs(n-(i+c+1)));
		if(c>=1)
		{
			fl=1;
			if(t[i]==0)d0=min(d0,dis);
			else d1=min(d1,dis);
		}
		i=i+c;
	}
	if(!fl)return t[1];
	if(d0<d1)return 0;
	else return 1;
}
int main()
{
	scanf("%d",&n),s=n*2-1;
	int l=0,r=0,mid;
	for(int i=1;i<=s;++i)scanf("%d",&a[i]),r=max(r,a[i]);
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
