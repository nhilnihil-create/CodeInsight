#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()


int main(int argc, char **argv)
{
	ll N, L; cin >> N >> L;
	vector<ll> A(N);
	REP(i, N) cin >> A[i];

	bool ok{false};
	ll j;
	REP(i, N-1)
	{
		if (A[i] + A[i+1] >= L)
		{
			ok = true;
			j = i;
		}
	}

	if (!ok)
	{
		std::cout << "Impossible"<< std::endl;
		return 0;
	}

	std::cout << "Possible" << std::endl;
	REP(i, j)
		std::cout << i+1 << std::endl;
	for (ll i = N-2; i >= j; --i)
		std::cout << i+1 << std::endl;
}
