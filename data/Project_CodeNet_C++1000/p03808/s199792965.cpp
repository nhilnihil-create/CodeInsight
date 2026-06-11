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
int sum,w;
int n,cnt,a[N];
main()
{
	re(n);
	for(int i=1;i<=n;++i)
		re(a[i]),sum+=a[i];
	w=n*(n+1ll)/2;
	if(sum%w)
	{
		puts("NO");
		return 0;
	}
	sum/=w;
	a[0]=a[n];
	for(int i=n;i;--i)a[i]-=a[i-1];
	for(int i=1;i<=n;++i)
	{
		int x=sum-a[i];
		if(x<0 || x%n)
		{
			puts("NO");
			return 0;
		}
		x/=n;
		cnt+=x;
	}
	if(cnt!=sum)puts("NO");
	else puts("YES");
}
/*
a[i]+(n-1)x-(sum-x) =0
a[i]-sum+nx=0
nx=sum-a[i]
*/
/*
3 4 5  1 2
1 1 1 -4 1
*/
