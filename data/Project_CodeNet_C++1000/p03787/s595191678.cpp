#include <bits/stdc++.h>
#define rank tipa_rank
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 1000000000
#define EPS 1e-6
#define free tipa_free
#define EPS2 1e-8
using namespace std;
const ll MOD = INF + 7;
using namespace std;
ll ans = 0;
int n , m;
int visited[100000];
ll trees , cycles , free;
vector<vector<int> > g(100000);
int edgesCnt = 0 , verticesCnt;
bool bipatride;
void dfs(int u)
{
	for(int i = 0; i < g[u].size(); i++)
	{
		edgesCnt++;
		int v = g[u][i];
		bool Dfs = false;
		if(!visited[v])
			Dfs = true;
		if(visited[u] == 1)
		{
			if(visited[v] == 1)
				bipatride = false;
			visited[v] = 2;
		}
		if(visited[u] == 2)
		{
			if(visited[v] == 2)
				bipatride = false;
			visited[v] = 1;
		}
		if(Dfs)
			dfs(v);
	}
}
int main()
{
	scanf("%d %d" , &n , &m);
	for(int i = 0; i < m; i++)
	{
		int u , v;
		scanf("%d %d" , &u , &v);
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			edgesCnt = 0;
			bipatride = true;
			visited[i] = 1;
			//edgesCnt++;
			dfs(i);
			if(!edgesCnt)
				free++;
			else if(bipatride)
			{
				trees++;
			}
			else
				cycles++;
		}
	}
	//cout << trees << " " << cycles << " " << free << endl;
	int x = n * 2 - 1;
	for(int i = 0; i < free; i++)
	{
		ans += x;
		x -= 2;
	}
	ans += cycles * (trees + cycles) + trees * (cycles + 2 * trees);
	cout << ans;
}
