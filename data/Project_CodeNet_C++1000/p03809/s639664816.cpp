#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
vector<int> e[N];
ll res[N];
void dfs(int x,int fa){
	res[x]=(e[x].size()>1?2*a[x]:a[x]);
	ll Max=0;
	for (int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if (v==fa) continue;
		dfs(v,x);
		res[x]-=res[v];
		Max=max(Max,res[v]);
	}
	if (res[x]<0) puts("NO"),exit(0);
	if (!fa&&res[x]) puts("NO"),exit(0);
	Max=max(Max,res[x]);
	if (Max>a[x]) puts("NO"),exit(0);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	puts("YES");
	return 0;
}