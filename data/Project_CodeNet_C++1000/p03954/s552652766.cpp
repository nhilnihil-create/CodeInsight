#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200005],l=0x7fffffff,r;
void init()
{
	cin>>n;
	for(int i=1;i<(n<<1);i++)
	{
		scanf("%d",&a[i]);
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
}
int c[200005];
bool check(int x)
{
	for(int i=1;i<(n<<1);i++)
	{
		if(a[i]>=x) c[i]=1;
		else c[i]=0;
	}
	int t=0;
	for(int j=1;j<n;j++)
	if(c[n-j+1]==c[n-j]||c[n+j]==c[n+j-1])
	{t=j;break;}
	if(t==0)
	{
		c[n]=c[n]^((n-1)&1);
		return c[n];
	}
	if(c[n-t+1]==c[n-t])
	return c[n-t+1];
	else
	return c[n+t-1];
}
void play()
{
	int mid;
	while(l<r)
	{
		 mid=(l+r+1)>>1;
		 if(check(mid)) l=mid;
		 else r=mid-1;
	}
	cout<<l<<endl;
}
int main()
{
	init();
	play();
	return 0;
}