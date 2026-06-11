#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 100010
#define ll long long
using namespace std;
int n, d[N], m, s[N], x, b[N], pos[N], p[N], flag[N], l;
ll w[N], k;
vector<int>son[N];
inline void dfs(int x){
	son[l].push_back(x); flag[x]=1; p[x]=l; pos[x]=son[l].size()-1;
	if(!flag[b[x]])dfs(b[x]);
}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%lld", &w[i]);
	for(int i=1; i<=n-1; i++)d[i]=w[i+1]-w[i];
	scanf("%d%lld", &m, &k);
	for(int i=1; i<=n-1; i++)b[i]=i;
	for(int i=1; i<=m; i++){scanf("%d", &x); swap(b[x-1], b[x]);}
	for(int i=1; i<=n-1; i++)pos[b[i]]=i; memcpy(b, pos, sizeof(b));
	l=0; memset(flag, 0, sizeof(flag));
	for(int i=1; i<=n-1; i++)if(!flag[i]){l++; son[l].clear(); dfs(i);}
	for(int i=1; i<=n-1; i++){
		x=(k+pos[i])%son[p[i]].size();
		s[son[p[i]][x]]=d[i];
	}
	for(int i=1; i<=n-1; i++)w[i+1]=w[i]+s[i];
	for(int i=1; i<=n; i++)printf("%lld\n", w[i]);
	return 0;
}