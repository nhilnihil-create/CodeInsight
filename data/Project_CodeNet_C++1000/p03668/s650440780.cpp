#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> G[100005];

int dfs(int v, int prev)
{
	int ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		ret ^= dfs(G[v][i], v);
	}
	return ret + 1;
}

int main(void)
{
	cin >> N;
	int x, y;
	for(int i = 1; i <= N-1; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	int ans = 0;
	for(int i = 0; i < G[1].size(); i++){
		ans ^= dfs(G[1][i], 1);
	}
	
	if(ans) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	return 0;
}