#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL K;
LL ans[51];

int main()
{
	in >> K;

	if (K == 0) { out << 4 << std::endl << 3 << " " << 3 << " " << 3 << " " << 3 << std::endl; }
	else if (K == 1) { out << 3 << std::endl << 1 << " " << 0 << " " << 3 << std::endl; }
	else if (2LL <= K && K < 50LL)
	{
		out << K << std::endl;
		rep(i, K - 1) { out << K << " "; }
		out << K << std::endl;
	}
	else
	{
		out << 50 << std::endl;
		rep(i, 50) { ans[i] = i + K / 50; }
		rep(i, K % 50) { ++ans[49 - i]; }
		rep(i, 49) { out << ans[i] << " "; }
		out << ans[49] << std::endl;
	}
	return 0;
}