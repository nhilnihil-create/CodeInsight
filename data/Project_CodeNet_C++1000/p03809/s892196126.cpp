#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+50;
const ll inf=1e16;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int head[N],nn[N][2],d[N],a[N],cnt,flag;
ll ans,w[N],f[N];
#define link(u,v) (nn[++cnt][1]=v,nn[cnt][0]=head[u],head[u]=cnt,++d[v])
void dfs(int x,int fa){
    if (d[x]==1){
	f[x]=a[x]; return;
    }
    ll sum=0,mx=-inf;
    for (int i=head[x],y; i; i=nn[i][0])
	if ((y=nn[i][1])!=fa){
	    dfs(y,x),sum+=f[y];
	    mx=max(mx,f[y]);
	}
    if (sum<a[x]||sum>2*a[x]||mx>a[x])
	flag=1;
    f[x]=2*a[x]-sum;
    return;
}
int main(){
    int n=gi(),x,y;
    for (int i=1; i<=n; ++i)
	a[i]=gi();
    for (int i=1; i<n; ++i)
	x=gi(),y=gi(),link(x,y),link(y,x);
    if (n==2)
	return puts(a[1]==a[2]?"YES":"NO"),0;
    for (int i=1; i<=n; ++i)
	if (d[i]!=1){
	    dfs(i,0);
	    if (f[i]!=0) flag=1;
	    break;
	}
    puts(flag?"NO":"YES");
    return 0;
}
