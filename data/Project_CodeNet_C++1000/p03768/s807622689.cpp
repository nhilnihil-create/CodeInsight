#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int head[N],nn[N][2],cnt,f[N],v[N],d[N],c[N];
int col[N],st[N],g[N],vis[N];
#define link(x,y) (nn[++cnt][1]=y,nn[cnt][0]=head[x],head[x]=cnt)
void bfs(int x,int D,int cl){
    int l=0,r=1,s,t; st[1]=x,g[1]=D;
    while(l<r){
	s=st[++l];
	if (!vis[s]) vis[s]=1,col[s]=cl;
	if (g[l]<=f[s]) continue;
	f[s]=g[l];
	for (int i=head[s]; i; i=nn[i][0])
	    t=nn[i][1],st[++r]=t,g[r]=g[l]-1;
    }
    return;
}
int main(){
    int n=gi(),m=gi(),q,x,y;
    for (int i=1; i<=m; ++i)
	x=gi(),y=gi(),link(x,y),link(y,x);
    q=gi();
    for (int i=1; i<=q; ++i)
	v[i]=gi(),d[i]=gi(),c[i]=gi();
    for (int i=q; i>=1; --i)
	bfs(v[i],d[i],c[i]);
    for (int i=1; i<=n; ++i)
	printf("%d\n",col[i]);
    return 0;
}
