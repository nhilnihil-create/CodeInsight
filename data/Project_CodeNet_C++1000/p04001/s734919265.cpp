// 2^n 全探索

#include  <iostream>
#include  <vector>
#include  <string>
#include  <cstdlib>
#include  <cmath>

long long solve0(long long var);


int main(void)
{
	long long in;
	std::cin >> in;

	long long ans = 0;
	ans = solve0(in);

	std::cout << ans << std::endl;

	return EXIT_SUCCESS;
}

long long solve0(long long var)
{
	long long rtn = 0;
	int n = (int)std::log10(var) + 1;

	// 全パターン探索
	for(int bit = 0; bit < (1 << n-1); ++bit) {
		std::vector<long long> v;
		long long p = var, q = std::pow(10, n-1);

		for(int i = 0; i < n; ++i) {	
			if(bit & (1 << i)) {
				v.push_back(p / q);
				p = p % q;
			}
			q = q / 10;
		}

		v.push_back(p);

		for(std::vector<long long>::iterator it = v.begin(); it != v.end(); ++it)
			rtn += *it;
	}

	return rtn;
}


