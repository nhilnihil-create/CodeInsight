// 2^n 全探索

#include  <iostream>
#include  <vector>
#include  <cstdlib>
#include  <cmath>

long long solve0(long long var); // bit全探索
long long solve1(long long var); // 再起全探索
long long solve11(long long p, int q); // 再起全探索(探索の実体)


int main(void)
{
	long long n;
	std::cin >> n;

	long long ans = 0;
	ans = solve0(n);
	//ans = solve0(n);

	std::cout << ans << std::endl;

	return EXIT_SUCCESS;
}

long long solve0(long long var)
{
	long long rtn = 0;
	int d = (int)std::log10(var) + 1;

	// 全パターン探索
	for(int bit = 0; bit < (1 << d-1); ++bit) {
		std::vector<long long> v;
		long long p = var, q = std::pow(10, d-1);

		for(int i = 0; i < d; ++i) {	
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

long long solve1(long long var)
{
	long long rtn = 0;
	int d = (int)std::log10(var) + 1;

	rtn = solve11(var, std::pow(10, d-1));

	return rtn;
}

long long solve11(long long p, int q)
{
	long long rtn = 0;

	if(q == 0)
		return p;
	else
		// (1) '+'を挿入する, (2) '+'を挿入しない
		rtn = solve11(p % q, q / 10) + solve11(p, q / 10);

	return rtn;
}

