#include<bits/stdc++.h>
const int MN=200000+5,P=998244353,inv2=P+1>>1;
using namespace std;
typedef long long ll;
template<typename T>inline T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n,K,ans;
int a[MN],dep[MN],vis[MN];
int nxt[MN],to[MN],h[MN],cnt;
void add(int u,int v){to[cnt]=v,nxt[cnt]=h[u],h[u]=cnt++;}
void dfs(int u){
	dep[u]=1;
	for(int e=h[u],v=to[e];~e;e=nxt[e],v=to[e]){
		dfs(v);
		if(!vis[v])dep[u]=max(dep[u],dep[v]+1);
	}
	if(u!=1&&dep[u]==K&&a[u]!=1)vis[u]=1,ans++;
}
int input(){
	IN(n),IN(K);memset(h,-1,sizeof h);
	for(int i=1;i<=n;++i)IN(a[i]);
	for(int i=2;i<=n;++i)add(a[i],i);
	if(a[1]!=1)ans++;
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	input();
	return 0;
}