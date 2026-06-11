#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

const lli maxn = lli(1e5)+5;

lli vis[maxn], type[2];
vector<lli> graph[maxn];

lli dfs(lli node, lli parity)
{
	vis[node] = parity;
	lli ret = 1;
	for(auto it: graph[node])
	{
		if(vis[it] == -1)
		{
			ret = min(ret, dfs(it, !parity));
		}
		else ret = min(ret, lli(vis[it] == (!parity)));
	}
	return ret;
}

int main(void)
{
	lli n, m, u, v;
	scanf("%lld%lld", &n, &m);
	for(lli i = 0;i < n;i++) vis[i] = -1;
	vector<lli> process;
	while(m--)
	{
		scanf("%lld%lld", &u, &v);
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	lli res = 0, iso = 0;
	for(lli i = 0;i < n;i++)
	{
		if(vis[i] == -1)
		{
			lli x = dfs(i, 0);
			if(graph[i].empty()) iso++;
			else type[x]++;
		}
	}

	//cout << iso << " " << type[0] << " " << type[1] << "\n";
	//combo = (isolated, something)
	res += iso*(n*2ll-iso);
	//combo = (bipartite, bipartite)
	res += type[1]*type[1]*2;
	//combo = (non-bipartite, something non isolated)
	res += type[0]*(type[1]*2+type[0]);
	printf("%lld\n", res);
}