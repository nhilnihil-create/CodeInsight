#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],root;
vector<int> G[N];
ll sum;
ll dfs(int u,int fa){
	if(G[u].size()==1)return a[u];
	ll tot=0,mx=0;
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if(v==fa)continue;
		ll p=dfs(v,u);
		if(p<0)return -1;
		mx=max(mx,p);
		tot+=p;
	}
	if(a[u]>tot||a[u]<(tot+1)/2)return -1;
	ll o=tot-a[u];
	if(o>tot-mx)return -1;
	return 2*a[u]-tot;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n==2){
		puts(a[1]==a[2]?"YES":"NO");
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(G[i].size()>1){
			root=i;break;
		}
	}
	puts(!dfs(root,0)?"YES":"NO");
	return 0;
}
