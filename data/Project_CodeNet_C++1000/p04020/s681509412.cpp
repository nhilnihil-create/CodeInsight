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
	for (ll i = 0; i < N;)
	{
		ll j = i;
		ll sum{0};
		while (j < N && A[j])
		{
			sum += A[j];
			++j;
		}

		res += sum/2;
		i = j + 1;
	}
	std::cout << res << std::endl;
}
