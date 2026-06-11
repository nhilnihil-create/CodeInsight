#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,m;
vector <int> e[N];
LL ans;
int vis[N],c[N];
int tot=0,size=0,sz=0;
int dfs(int x,int f){
	vis[x]=1;
	c[x]=f;
	sz++;
	int res=0;
	for (auto y : e[x])
		if (!vis[y])
			res|=dfs(y,f^1);
		else
			res|=c[x]==c[y];
	return res;
}
void solve(int x){
	if (e[x].empty())
		return;
	size++;
	tot+=dfs(x,0)^1;
}
LL _2(int x){
	return 1LL*x*x;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++)
		if (!vis[i])
			solve(i);
	ans=_2(n)-_2(sz)+_2(size)+_2(tot);
	cout << ans;
	return 0;
}
//单点情况特殊考虑
/*
8 5
2 3
3 4
2 4
5 6
6 7
ans = 33

*/