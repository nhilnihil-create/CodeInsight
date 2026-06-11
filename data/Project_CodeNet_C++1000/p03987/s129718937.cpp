#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=200050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,a[maxn],l[maxn],r[maxn];
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		l[i]=i;ll j=i;
		while(j>=1&&a[l[j]-1]>=a[i]) j=l[l[j]-1];
		l[i]=j;
	}
	
	for(ll i=n;i>=1;i--)
	{
		r[i]=i;ll j=i;
		while(j<=n&&a[r[j]+1]>=a[i]) j=r[r[j]+1];
		r[i]=j;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]*(i-l[i]+1)*(r[i]-i+1);
	cout<<ans<<endl;
	return 0;
}