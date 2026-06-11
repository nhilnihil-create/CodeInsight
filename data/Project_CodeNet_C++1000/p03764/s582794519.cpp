#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

const LL mod = 1000000007;
LL n, m, xsum, left, ysum, right;

int main()
{
	in >> n >> m;
	std::vector<LL>x(n), y(m);
	rep(i, n) in >> x[i];
	rep(i, m) in >> y[i];
	xsum = x[0];
	for (int i = 1; i < n; ++i)
	{
		left += x[i] * i - xsum;
		xsum += x[i];
		left %= mod;
	}
	ysum = y[0];
	for (int i = 1; i < m; ++i)
	{
		right += y[i] * i - ysum;
		ysum += y[i];
		right %= mod;
	}
	out << (left*right) % mod << std::endl;
	return 0;
}
