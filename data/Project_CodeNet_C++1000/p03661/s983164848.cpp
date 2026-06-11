#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N;
	in >> N;
	std::vector<LL>a(N);
	rep(i, N) in >> a[i];

	std::vector<LL>a_imos(N + 1);
	rep(i, N) a_imos[i + 1] = a_imos[i] + a[i];

	LL ans = 1145148101919;
	for (LL i = 1; i < N; ++i)
	{
		LL x = a_imos[i], y = a_imos[N] - a_imos[i];
		ans = std::min(ans, std::abs(x - y));
	}

	out << ans << std::endl;
}
