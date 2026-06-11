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
        ll s = 0;
	for(auto &u : graph[a])
	{
		if(!visited[u])
		{
			s ^= (dfs(u) + 1);
		}
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