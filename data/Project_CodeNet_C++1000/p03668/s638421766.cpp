#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 1e5 + 10;

vector<int> graph[MAX_SIZE];
vector<bool> visited(MAX_SIZE);

ll dfs(int a)
{
	visited[a] = true;
	vector<ll> G;
	for(auto &u : graph[a])
	{
		if(!visited[u])
		{
			G.pb(dfs(u));
		}
	}
	if(G.size() == 1)
		return 1 + G[0];
	else if(G.size() == 0)
		return 0;
	ll s = 0;
	for(auto &g : G)
	{
		s ^= (g + 1);
	}
	return s;
}

int main()
{
	int N;
	cin >> N;
	int x, y;
	for(int i = 1; i < N; i++)
	{
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
		visited[x] = false;
		visited[y] = false;
	}
	ll s = dfs(1);
	if(s == 0)
		cout << "Bob" << endl;
	else
		cout << "Alice" << endl;
	return 0;
}