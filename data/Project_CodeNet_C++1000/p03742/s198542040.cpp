#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL X, Y;

int main()
{
	in >> X >> Y;
	out << (abs(X - Y) >= 2 ? "Alice" : "Brown") << std::endl;
	return 0;
}
