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
int n,x;
int ans[200005];
bool use[200005];
int main()
{
	re(n),re(x);
	if(x==1 || x==2*n-1)
	{
		puts("No");
		return 0;
	}
	if(x!=2)
		ans[n]=x,ans[n+1]=x+1,ans[n+2]=x-2,ans[n-1]=x-1;
	else 
		ans[n]=x,ans[n+1]=x-1,ans[n+2]=x+2,ans[n-1]=x+1;
	for(int i=1;i<=2*n-1;++i)
		use[ans[i]]=1;
	puts("Yes");
	for(int i=1,j=1;i<=2*n-1;++i)
	{
		while(use[j])++j;
		if(ans[i])printf("%d\n",ans[i]);
		else printf("%d\n",j),use[j]=1;
	}	
}