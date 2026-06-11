#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll dp[210][210];

int main(int argc, char **argv)
{
	ll N, M, R;
	cin >> N >> M >> R;
	vector<ll> r(R); REP(i, R) cin >> r[i], --r[i];

	REP(i, N) REP(j, N) dp[i][j] = INF;
	REP(i, M)
	{
		ll s, t, d; cin >> s >> t >> d;
		--s, --t;
		dp[s][t] = d;
		dp[t][s] = d;
	}

	REP(v, N)REP(s, N)REP(g, N)
		dp[s][g] = min(dp[s][v] + dp[v][g], dp[s][g]);

	sort(ALL(r));
	ll res{INF};
	do
	{
		ll tmp{0};
		REP(i, R-1)
		{
			tmp += dp[r[i]][r[i+1]];
		}
		res = min(res, tmp);
	} while (next_permutation(ALL(r)));

	std::cout << res << std::endl;
}
