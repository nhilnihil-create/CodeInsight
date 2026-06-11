#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200050;
ll n,a[maxn],sta[maxn],top;
ll l[maxn],r[maxn];
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[sta[top]]>=a[i]) top--;
		if(top) l[i]=sta[top];
		else l[i]=0;
		sta[++top]=i;
	}
	memset(sta,0,sizeof(sta));top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[sta[top]]>=a[i]) top--;
		if(top) r[i]=sta[top];
		else r[i]=n+1;
		sta[++top]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=(i-l[i])*(r[i]-i)*a[i];
	//for(int i=1;i<=n;i++) cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<a[i]<<endl; 
	cout<<ans<<endl;
	return 0;
}

