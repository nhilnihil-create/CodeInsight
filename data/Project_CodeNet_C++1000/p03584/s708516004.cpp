#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, K, ans, res;

int main()
{
	in >> N >> K;
	std::vector<LL>A(N), B(N);
	rep(i, N)
	{
		in >> A[i] >> B[i];
		if (A[i] > K) B[i] = 0;
	}
	rep(k, 30)
	{
		if (K & (1LL << k))
		{
			LL tmp = 0;
			rep(i, N)
			{
				bool flag = !(A[i] & (1LL << k));
				for (int j = k + 1; j < 30; ++j)
				{
					if ((A[i] & (1LL << j)) && !(K & (1LL << j)))
					{
						flag = false;
						break;
					}
				}
				if (flag) tmp += B[i];
			}
			ans = std::max(ans, tmp);
		}
	}
	rep(i, N)
	{
		bool flag = true;
		rep(k, 30)
		{
			if (!(K & (1LL << k)) && (A[i] & (1LL << k)))
			{
				flag = false;
				break;
			}
		}
		if (flag) res += B[i];
	}
	out << std::max(ans, res) << std::endl;
	return 0;
}
