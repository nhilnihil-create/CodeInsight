#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	int H, W;
	in >> H >> W;
	std::vector<std::vector<std::string>>S(H, std::vector<std::string>(W));
	rep(i, H) rep(j, W) in >> S[i][j];

	rep(i, H)
	{
		rep(j, W)
		{
			if (S[i][j] == "snuke")
			{
				char c = 'A' + j;
				out << c << i + 1 << std::endl;
				return 0;
			}
		}
	}
}
