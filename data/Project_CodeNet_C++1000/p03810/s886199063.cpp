//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,a[N];
main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]);
	if(n%2==0)
	{
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=a[i]-1;
		puts(sum&1?"First":"Second");
	}
	else
	{
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=a[i]-1;
		if(sum&1)
		{
			puts("First");
			return 0;
		}
		int now=0;
		while(1)
		{
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(a[i]&1)
				{
					if(cnt || a[i]==1)
					{
						puts(now?"First":"Second");
						return 0;
					}
					++cnt;
					--a[i];
				}
			sum=0;
			int gcd=a[1];
			for(int i=2;i<=n;++i)
				gcd=__gcd(gcd,a[i]);
			for(int i=1;i<=n;++i)
				a[i]/=gcd,sum+=a[i]-1;
			if(sum&1)
			{
				puts(now?"First":"Second");
				return 0;
			}
			now^=1;
		}
	}
}
//3 4 4 4 4
/*
n%2==0
n
xyn - > yn
xyn-n -> yn-n

n%2==1

xyn - > yn
xyn-n -> yn-n
(xy-1)n -> (y-1)n

x%2==0 && y%2==1

(xy-1)n+1%2=0

*/
