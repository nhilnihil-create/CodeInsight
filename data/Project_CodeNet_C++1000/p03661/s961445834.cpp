#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e8
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
ll a[200001],sum[200001],ans=1e17,n;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	sum[i]=sum[i-1]+a[i];
	Dow(i,1,n-1)
		ans=min(ans, abs(sum[n]-sum[i]-sum[i]) );
	cout<<ans<<endl;
}