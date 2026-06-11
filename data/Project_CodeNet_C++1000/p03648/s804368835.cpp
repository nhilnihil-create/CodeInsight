#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL K;
	in >> K;

	std::vector<LL>ans;
	if (K == 0) ans.resize(2, 1);
	else if (K == 1)
	{
		ans.push_back(0);
		ans.push_back(3);
	}
	else if (K <= 50) ans.resize(K, K);
	else
	{
		LL def = 49 + K / 50;
		ans.resize(50, def);
		rep(i, K % 50) ans[i] += 51 - K % 50;
		rep(i, 50 - K % 50) ans[(K % 50) + i] -= K % 50;
	}

	out << ans.size() << std::endl;
	rep(i, ans.size()) out << ans[i] << (i < ans.size() - 1 ? " " : "\n");
	return 0;
}
