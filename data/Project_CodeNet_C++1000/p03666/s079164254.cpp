//Heaplax
#include<bits/stdc++.h>
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
int n,a,b,c,d,f;
main()
{
	re(n),re(a),re(b),re(c),re(d);
	f=abs(a-b);
	for(int i=0;i<n;++i)
		if(c*(n-1-i)-d*i<=f && f<=-c*i+(n-1-i)*d)
			return puts("YES"),0;
	puts("NO");
}
