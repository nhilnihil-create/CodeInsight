//Heaplax
#include<bits/stdc++.h>
#define LL long long
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
int n,m,a,b;
int main()
{
	re(n),re(m),re(a),re(b);
	if(n%a==0 && m%b==0)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
		{
			if(n%a!=0)
				printf("%d ",i%a?555:-(555*(a-1)+1));
			else 
				printf("%d ",j%b?555:-(555*(b-1)+1));
		}
}
/*
x * H/h
y * H-H/h

x=(h-1)y+1
x * H/h  < y * (H-H/h)
*/
