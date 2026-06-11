#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define lowbit(x) (x)&(-x)
#define fir first
#define sec second
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define maxd 1000000007
typedef long long ll;
const int N=100000;
const double pi=acos(-1.0);
int n,m,a[100100],tmp[100100],d[100100],ans[100100];
ll k;
double f[100100];

int read()
{
	int x=0,f=1;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}

int main()
{
	n=read();
	rep(i,1,n) 
	{
		a[i]=read();d[i]=i;ans[i]=i;
	}
	m=read();scanf("%lld",&k);
	rep(i,1,m)
	{
		int x=read();
		swap(d[x],d[x+1]);
	}
	while (k)
	{
		if (k&1)
		{
			rep(i,1,n) tmp[i]=ans[d[i]];
			rep(i,1,n) ans[i]=tmp[i];
		}
		k>>=1;
		rep(i,1,n) tmp[i]=d[d[i]];
		rep(i,1,n) d[i]=tmp[i];
	}
	rep(i,1,n) f[i]=a[ans[i]]-a[ans[i]-1];
	rep(i,1,n) f[i]+=f[i-1];
	rep(i,1,n) printf("%.1lf\n",f[i]);
	return 0;
}
