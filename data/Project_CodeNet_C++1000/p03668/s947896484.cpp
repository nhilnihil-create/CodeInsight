#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
//#define max(a,b) ((a)<(b)?(b):(a))
//#define min(a,b) ((a)<(b)?(a):(b))
//#define swap(a,b) a^=b^=a^=b
#define lb(x) ((x)&(-(x)))
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 100010
using namespace std;
typedef long long ll;
int n,f[N],a,b;
vector<int> g[N];
inline void dfs(int x,int p){
	for(int i=0;i<g[x].size();i++)if(g[x][i]^p)dfs(g[x][i],x),f[x]^=(f[g[x][i]]+1);
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
	dfs(1,0);
	puts(f[1]?"Alice":"Bob");
	return 0;
}