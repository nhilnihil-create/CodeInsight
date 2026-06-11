#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 1000005
using namespace std;
int nxt[M],head[M],to[M],tot,n;
int read(){
	char c=getchar();int ans=0; 
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans; 
}
void add(int u,int v){nxt[++tot]=head[u];head[u]=tot;to[tot]=v;return;}
int DFS(int x,int fa){
	int ans=0;
	for (register int i=head[x];i;i=nxt[i])
		if (to[i]!=fa) ans^=(DFS(to[i],x)+1);
	return ans;
}
int main(){
	n=read();
	for (register int i=1,u,v;i<n;i++) u=read(),v=read(),add(u,v),add(v,u);
	printf("%s",DFS(1,0)?"Alice":"Bob");
	return 0;
}
