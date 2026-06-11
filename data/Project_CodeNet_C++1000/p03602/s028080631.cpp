#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, ans;
std::vector<std::vector<LL>>dist;
std::vector<std::vector<bool>>flag;

bool warshall_floyd(LL V)
{
	for (LL k = 0; k < V; ++k)
	{
		for (LL i = 0; i < V; ++i)
		{
			for (LL j = 0; j < V; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j]) return false;
				if (dist[i][j] == dist[i][k] + dist[k][j] && (i != k && k != j)) flag[i][j] = true;
			}
		}
	}
	return true;
}

int main()
{
	in >> N;
	dist.resize(N);
	flag.resize(N);
	rep(i, dist.size()) dist[i].resize(N);
	rep(i, flag.size()) flag[i].resize(N);
	rep(i, N) rep(j, N) in >> dist[i][j];
	if (!warshall_floyd(N)) out << -1 << std::endl;
	else
	{
		rep(i, N) rep(j, i + 1) ans += (!flag[i][j] ? dist[i][j] : 0);
		out << ans << std::endl;
	}
	return 0;
}
