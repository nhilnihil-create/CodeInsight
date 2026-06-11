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
#define N 200001
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
bool check(int m)/// ? <= x
{
	int x=N,y=N;
	for(int i=1;i<n+n-1;++i)
		if(a[i]<=m && a[i+1]<=m)
			x=min(x,min(abs(n-i),abs(n-i-1)));
		else if(a[i]>m && a[i+1]>m)
			y=min(y,min(abs(n-i),abs(n-i-1)));
	return x<y || (x==y && a[1]<=m);
}
int main()
{
	re(n);
	for(int i=1;i<n+n;++i)re(a[i]);
	int l=1,r=n+n-1;
	while(l < r)
	{
		int m=l+r>>1;
		if(check(m))r=m;
		else l=m+1;
	}
	printf("%d\n",l);
}