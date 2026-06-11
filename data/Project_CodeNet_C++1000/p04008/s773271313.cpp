#include <bits/stdc++.h>
using std::queue;
const int N=100005;
int to[N<<1],edge,last[N],Next[N<<1],son[N],a[N],f[N],n,k,deep[N];
int ans;
queue <int> q;
void add(int x,int y){
	to[++edge]=y;
	Next[edge]=last[x];
	last[x]=edge;
}
void dfs(int x,int fa){
	f[x]=fa;
	for (int i=last[x];i;i=Next[i])
		if (to[i]!=fa){
			dfs(to[i],x);
			son[x]++;
		}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	if (a[1]!=1) ans=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]),add(a[i],i);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) 
		if (son[i]==0) q.push(i),deep[i]=1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		if (x==1) break;
		if (deep[x]>=k && f[x]!=1){
			deep[x]=0;
			ans++;
		}
		deep[f[x]]=std::max(deep[f[x]],deep[x]+1);
		son[f[x]]--;
		if (!son[f[x]]) q.push(f[x]);
	}
	printf("%d\n",ans);
}