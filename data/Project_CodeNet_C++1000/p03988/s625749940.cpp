#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 101
#define LL long long
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
int need[N],use[N];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]);
	sort(a+1,a+n+1);
	for(int i=a[n]/2+1;i<=a[n];++i)
		need[i]=2;
	if(a[n]%2==0)++need[a[n]/2];
	for(int i=1;i<=n;++i)
		if(need[a[i]])
			--need[a[i]],use[i]=1;
	for(int i=1;i<=n;++i)
		if(need[i])
		{
			puts("Impossible");
			return 0;
		}
	for(int i=1;i<=n;++i)
		if(!use[i] && a[i]<(a[n]+3)/2)
		{
			puts("Impossible");
			return 0;
		}
	puts("Possible");
}