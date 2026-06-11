#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int tt;
int head[N],to[N*2],nxt[N*2],la[N],ans[N],f[N][11],g[N][11];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n,m,q;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
	int x=gi(),y=gi();
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    cin>>q;
    for(int i=1;i<=q;i++) {
	int x=gi(),y=gi(),z=gi();
	g[x][y]=i,f[x][y]=z;
    }
    for(int t=10;~t;t--)
	for(int x=1;x<=n;x++)
	    if(g[x][t]) {
		if(g[x][t]>la[x]) la[x]=g[x][t],ans[x]=f[x][t];
		if(!t) continue;
		for(int i=head[x];i;i=nxt[i]) {
		    int y=to[i];
		    if(g[y][t-1]<g[x][t])
			g[y][t-1]=g[x][t],f[y][t-1]=f[x][t];
		}
	    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}