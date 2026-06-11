#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k,ans;
int head[100100],nxt[100100],to[100100],cnt=0;
int TO[100100];
void add(int x,int y){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int dfs(int u,int depth){
	int rest_max=depth;
	for (int i=head[u];i;i=nxt[i])
		rest_max=max(rest_max,dfs(to[i],depth+1));
	if (TO[u]!=1&&rest_max-depth==k-1) {
		ans++;return 0;
	}
	return rest_max;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&TO[i]);
		if (i==1){
			if (TO[i]==1) ans=0;else ans=1;
			TO[i]=1;
		}else {
			add(TO[i],i);//¼Ó·´Ïò±ß 
		}
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
