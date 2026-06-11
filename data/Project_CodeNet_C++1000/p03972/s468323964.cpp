#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL W, H, c1, c2, ans;
std::vector<std::pair<LL, LL>>edge;

int main()
{
	in >> W >> H;
	std::vector<LL>p(W), q(H);
	rep(i, W)
	{
		in >> p[i];
		edge.push_back(std::make_pair(p[i], 0));
	}
	rep(i, H)
	{
		in >> q[i];
		edge.push_back(std::make_pair(q[i], 1));
	}
	std::sort(edge.begin(), edge.end());
	c1 = H + 1, c2 = W + 1;
	for (auto e : edge)
	{
		if (e.second == 0)
		{
			ans += e.first*c1;
			--c2;
		}
		else
		{
			ans += e.first*c2;
			--c1;
		}
	}
	out << ans << std::endl;
	return 0;
}
