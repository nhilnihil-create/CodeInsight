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
	ll N, M; cin >> N >> M;
	vector<ll> seen(N, 0);

	REP(i, M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;

		++seen[a];
		++seen[b];
	}

	bool ok{true};

	for (auto &e : seen)
	{
		if (e&1)
			ok = false;
	}
	std::cout << (ok ? "YES" : "NO") << std::endl;	
}