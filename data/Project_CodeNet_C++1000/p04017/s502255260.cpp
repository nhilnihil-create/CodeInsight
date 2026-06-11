#include<bits/stdc++.h>
#define inf 1e18
using namespace std;
typedef long long ll;
inline ll rd()
{
	ll x=0,p=1;
	char a=getchar();
	while((a<48||a>57)&&a!='-')a=getchar();
	if(a=='-')p=-p,a=getchar();
	while(a>47&&a<58)
	{
		x=(x<<1)+(x<<3)+(a&15);
		a=getchar();
	}
	return x*p;
}
inline void swap(ll &x,ll &y){ll t=x;x=y;y=t;}
const int N=100002;
ll n,l,q,d[N][40],a[N],lgn;
inline int div(ll k)
{
	int l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]>k)r=mid-1;
		else l=mid+1;
	}
	return r;
}
int main()
{
	n=rd();lgn=log2(n);
	for(int i=1;i<=n;i++)a[i]=rd();
	l=rd();q=rd();
	for(int i=1;i<=n;i++)d[i][0]=div(a[i]+l);
	for(int j=1;j<=lgn;j++)
		for(int i=1;i<=n;i++)
			d[i][j]=d[d[i][j-1]][j-1];
	while(q--)
	{
		ll x,y,ans=0;
		x=rd();y=rd();
		if(x>y)swap(x,y);
		for(int j=lgn;j>=0;j--)
			if(d[x][j]<y)x=d[x][j],ans+=(1<<j);
		printf("%lld\n",ans+1);
	}
	return 0;
}