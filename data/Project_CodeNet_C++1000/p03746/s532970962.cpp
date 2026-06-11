#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 8;
int a , b , n , m;
vector <int> nei[N] , ans;
bool mark[N];

void dfs(int v)
{
	mark[v] = 1;
	ans.push_back(v);
	for(int u : nei[v])
		if(!mark[u])
			return dfs(u);
}

int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		a-- , b--;
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	dfs(0);
	reverse(ans.begin() , ans.end());
	ans.pop_back();
	dfs(0);
	cout << ans.size() << endl;
	for(int j : ans)
		cout << j + 1 << " ";
}