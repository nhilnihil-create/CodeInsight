#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,l,t,a[maxn],w[maxn],ans[maxn],num;

int main()
{
	n=read(); l=read(); t=read(); rep(i,1,n) a[i]=read(),w[i]=read();
	rep(i,1,n)
	{
		if(w[i]==1)
		{
			num+=(a[i]+t)/l; num%=n;
			a[i]=(a[i]+t)%l;
		}
		else
		{
			num+=(a[i]-t)/l; num%=n; if(num<0) num+=n;
			a[i]=(a[i]-t)%l; if(a[i]<0) a[i]+=l,num--;
		}
	}
	sort(a+1,a+n+1);
	rep(i,1,n)
	{
		int tmp=(i+num)%n; if(tmp==0) tmp=n;
		printf("%d\n",a[tmp]);
	}
	return 0;
}