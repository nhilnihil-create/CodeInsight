#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>w[MAXN];
int n;
int dep[MAXN];
int a[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int u)
{
	int l=int(w[u].size());
	for(int i=0;i<l;i++)
	{
		int v=w[u][i];
		dfs(v);
	}
	for(int i=0;i<l;i++)
	{
		int v=w[u][i];
		a[i]=dep[v];
	}
	sort(a,a+l,cmp);
	dep[u]=0;
	for(int i=0;i<l;i++)
	{
		dep[u]=max(dep[u],a[i]+i+1);
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		w[v].push_back(i);
	}
	dfs(1);
	printf("%d\n",dep[1]);
	//fclose(stdin);
	//fclose(stdout);
}