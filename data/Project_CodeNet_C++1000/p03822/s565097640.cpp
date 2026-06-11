#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>

#define REDIRECT(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define CLOSEALL() fclose(stdin), fclose(stdout)

using namespace std;

const int MAXN = 1e5 + 10;

int N;
vector <int> tmp;
vector <int> Adj[MAXN];
int dep[MAXN], answer;

inline void addEdge(int u, int v)
{
	Adj[u].push_back(v);
	Adj[v].push_back(u);
}

void DFS(int cur, int fa)
{

	for(vector<int>::iterator itr = Adj[cur].begin(); itr != Adj[cur].end(); ++itr)
	{
		const int & to = *itr;
		if(to == fa)
			continue;
		DFS(to, cur);
	}

	tmp.clear();
	for(vector<int>::iterator itr = Adj[cur].begin(); itr != Adj[cur].end(); ++itr)
		if(fa != *itr)
			tmp.push_back(dep[*itr]);
	
	if(tmp.empty())
		return;
	
	sort(tmp.begin(), tmp.end());

	dep[cur] = tmp.front() + 1;
	for(vector<int>::iterator itr = tmp.begin() + 1; itr != tmp.end(); ++itr)
		dep[cur] = max(dep[cur], *itr) + 1;
}

int main()
{
	//REDIRECT("selection");

	scanf("%d", &N);
	for(int i = 2; i <= N; i++)
	{
		int fa;
		scanf("%d", &fa);
		addEdge(i, fa);
	}

	DFS(1, 0);

	printf("%d\n", dep[1]);
	CLOSEALL();
	return 0;
}
