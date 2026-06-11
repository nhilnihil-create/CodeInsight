#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

class UF
{
private:
	vector<int> root;
	vector<vector<int> > edge;

public:
	UF(int n)
	{
		root = vector<int>(n + 1, -1);
		edge = vector<vector<int> >(n + 1);
	}

	int getroot(int x)
	{
		if(root[x] == -1) return x;
		else return root[x] = getroot(root[x]);
	}

	void add(int x, int y)
	{
		edge[x].push_back(y);
		edge[y].push_back(x);
		x = getroot(x);
		y = getroot(y);
		if(x == y) return;
		if(x > y) swap(x, y);
		root[y] = x;
	}

	bool isbipartite(int x)
	{
		vector<int> checked(root.size(), -1);
		queue<int> qu;
		qu.push(x);
		checked[x] = 0;
		while(!qu.empty()){
			int node = qu.front();
			qu.pop();
			// cout << node << " " << checked[node] << endl;
			for(int i = 0; i < edge[node].size(); i++){
				int next = edge[node][i];
				if(checked[next] == checked[node]) return false;
				if(checked[next] < 0){
					checked[next] = (checked[node] + 1) % 2;
					qu.push(next);
				}
			}
		}
		return true;
	}
};

int main()
{
	long long int n, m;
	cin >> n >> m;
	UF uf(n);
	vector<bool> isnoedge(n + 1, true);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		uf.add(u, v);
		isnoedge[u] = false;
		isnoedge[v] = false;
	}
	long long int bipartite = 0, notbipartite = 0;
	long long int noedgenode = 0;
	for(int i = 1; i <= n; i++){
		if(isnoedge[i]){
			noedgenode++;
		} else if(uf.getroot(i) == i){
			if(uf.isbipartite(i)) bipartite++;
			else notbipartite++;
			// cout << i << " " << uf.isbipartite(i) << endl;
		}
	}
	long long int ans = 2 * bipartite * bipartite + 2 * bipartite * notbipartite + notbipartite * notbipartite;
	ans += 2 * n * noedgenode - noedgenode * (noedgenode + 1) + noedgenode;
	cout << ans << endl;
	return 0;
}