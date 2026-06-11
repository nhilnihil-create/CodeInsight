#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int ne[N],tot,n,fi[N],zz[N],sg[N],x,y;
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x,int y){
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y)dfs(zz[i],x),sg[x]^=sg[zz[i]]+1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		jb(x,y);jb(y,x); 
	}
	dfs(1,0);
	if (sg[1])puts("Alice");
	else puts("Bob");
} 