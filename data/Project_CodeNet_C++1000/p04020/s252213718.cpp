#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N); REP(i, N) cin >> A[i];

	ll res{0};

	ll pre{0};
	REP(i, N)
	{
		ll sum = pre + A[i];
		res += sum / 2;
		if ((sum & 1) && A[i] != 0)
			pre = 1;
		else
			pre = 0;

		// std::cout << "----------"<< std::endl;
		// std::cout << "i : " << i << std::endl;
		// std::cout << "sum : " << sum << std::endl;
		// std::cout << "res : " << res << std::endl;
	}

	std::cout <<  res << std::endl;
}
