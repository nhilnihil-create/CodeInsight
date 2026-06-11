#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;

	ll res;

	auto f = [](ll num)
			 {
				 ll res{1};
				 for (ll i = 2; i <= num; ++i)
					 (res *= i) %= MOD;
				 return res;
			 };

	if (abs(N - M) > 1) res = 0;
	else 
	{
		res = (f(N) * f(M)) % MOD;
		if (N == M)
			(res *= 2) %= MOD;
	}
	
	std::cout << res << std::endl;
}
