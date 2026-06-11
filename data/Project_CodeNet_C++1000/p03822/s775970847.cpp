#include<bits/stdc++.h>
using namespace std;
int n,a,f[100005];
int fir[100005],nxt[100005],to[100005],cnt;
vector<int> g[100005];

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

void dfs(int x){
	f[x]=0;
	for(int i=fir[x];i;i=nxt[i]){
		dfs(to[i]);
		g[x].push_back(f[to[i]]);
	}
	sort(g[x].begin(),g[x].end());
	reverse(g[x].begin(),g[x].end());
	for(int i=0;i<g[x].size();i++) f[x]=max(f[x],g[x][i]+i+1);
}

int main(){
	n=read();
	for(int i=2;i<=n;i++){
		a=read();
		to[++cnt]=i,nxt[cnt]=fir[a],fir[a]=cnt;
	}
	dfs(1);
	printf("%d\n",f[1]);

	return 0;
}