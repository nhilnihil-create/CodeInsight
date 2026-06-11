#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename T> void read(T &x) {
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') x =(x<<1)+(x<<3)+c-'0',c=getchar();x *= f;
}
const int N=1e5+10;
int n,val[N];
vector<int>edge[N];
void dfs(int x,int fa){
	int sum=0,mx=0;
	if(edge[x].size()==1)return;
	for(int i=0;i<edge[x].size();i++){
		int v=edge[x][i];
		if(v==fa)continue;
		dfs(v,x);sum+=val[v];mx=max(mx,val[v]);
	}
	if(val[x]>sum||sum>2*val[x]){
		puts("NO");exit(0);
	}
	if(sum-val[x]>sum-mx){
		puts("NO");exit(0);
	}
	val[x]-=sum-val[x];
	return;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(val[i]);
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);edge[u].push_back(v);edge[v].push_back(u);
	}
	if(n==2){
		if(val[1]==val[2])return puts("YES")*0;
		else return puts("NO")*0;
	}
	int x=1;
	while(edge[x].size()==1)x++;
	dfs(x,0);
	if(val[x]!=0)return puts("NO")*0;
	else return puts("YES")*0;
	return 0;
}
