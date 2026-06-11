#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;
 
LL N, K, ans;
 
int main()
{
	in >> N >> K;
	std::vector<LL>a(N), max(N + 1);
	rep(i, N)
	{
		in >> a[i];
		max[i + 1] = a[i];
	}
	rep(i, N) max[i + 1] = std::max(max[i + 1], max[i]);
	ans = 112345678901;
	rep(bit, (1LL << N))
	{
		std::vector<LL>idxs;
		rep(i, N)
		{
			if (bit&(1LL << i)) idxs.push_back(i);
		}
		if (idxs.size() != K) continue;
		LL maxH = 0, res = 0;
		rep(i, K)
		{
			maxH = std::max(maxH, max[idxs[i]]);
			if (a[idxs[i]] <= maxH)
			{
				++maxH;
				res += maxH - a[idxs[i]];
			}
			else maxH = a[idxs[i]];
		}
		ans = std::min(ans, res);
	}
	out << ans << std::endl;
	return 0;
}