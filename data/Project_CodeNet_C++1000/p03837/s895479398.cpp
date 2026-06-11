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

ll N, M;
ll A[1010], B[1010], C[1010];
ll d[110][110];

int main(int argc, char **argv)
{
	cin >> N >> M;
	REP(i, 110)REP(j, 110) d[i][j] = INF*(i!=j);
	REP(i, M)
	{
		ll a, b, c; cin >> a >> b >> c;
		--a, --b;
		A[i] = a;
		B[i] = b;
		C[i] = c;
		d[a][b] = d[b][a] = c;
	}

	REP(v, N)REP(s, N)REP(t, N)
		d[s][t] = min(d[s][t], d[s][v] + d[v][t]);

	ll res{M};
	REP(m, M)
	{
		bool ok{false};
		REP(j, N)
		{
			if (d[j][A[m]] == d[j][B[m]] + C[m]) ok = true;
		}
		res -= ok;
	}

	std::cout << res << std::endl;
}
