#include <cstdio>
#include <vector>
#define pb push_back
#define tl(x) ((int)x.size()-1)
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,u,v,ans;
vector<int> b[N];
int dfs(int x,int fa) {
	int j,ret=0;
	rep(j,0,tl(b[x]))
	if (b[x][j]!=fa)
		ret^=dfs(b[x][j],x)+1;
	return ret;
}
int main()
{
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n-1)
	{
		scanf("%d%d",&u,&v);
		b[u].pb(v); b[v].pb(u);
	}
	ans=dfs(1,1);
	if (ans) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}