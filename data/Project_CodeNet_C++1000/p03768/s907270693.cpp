#include<bits/stdc++.h>
#define rint register int
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
    while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();
    return f?s:-s;
}
int n,m,Q,s[100010],mmp[100010],cl[100010];
int col[100010],vis[100010][11],hxcAK[100010];
int tot,head[100010],ver[200010],nxt[200010];
void add(int x,int y){
    nxt[++tot]=head[x]; ver[tot]=y;
    head[x]=tot;
}
void dfs(int x,int dis,int cr){
	if(!hxcAK[x]) col[x]=cr,hxcAK[x]=1;
	vis[x][dis]=1;
	if(dis==0) return;
	for(rint i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(vis[y][dis-1]) continue;
		vis[y][dis-1]=1;
		dfs(y,dis-1,cr);
	}
}
int main(){
    n=read(); m=read();
    for(rint i=1,x,y;i<=m;++i){
        x=read(); y=read();
        add(x,y); add(y,x);
    }
    Q=read();
    for(rint i=1;i<=Q;++i)
        s[i]=read(),mmp[i]=read(),cl[i]=read();
    for(rint i=Q;i;--i) dfs(s[i],mmp[i],cl[i]);
    for(rint i=1;i<=n;++i) printf("%d\n",col[i]);
    return 0;
}
/*
14 10
1 4
5 7
7 11
4 10
14 7
14 3
6 14
8 11
5 13
8 3
8
8 6 2
9 7 85
6 9 3
6 7 5
10 3 1
12 9 4
9 6 6
8 2 3

*/