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
#define DEBUG(x) ;
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};



int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M; cin >> N >> M;
	vector<ll> a(N), b(N), c(M), d(M);
	REP(i, N) cin >> a[i] >> b[i];
	REP(i, M) cin >> c[i] >> d[i];

	auto f = [](ll a, ll b, ll c, ll d)
			 {
				 return abs(a - c) + abs(b - d);
			 };
		

	REP(i, N)
	{
		ll res{0};
		ll mi{INF};

		REP(j, M)
		{
			ll tmp = f(a[i], b[i], c[j], d[j]);
			if (mi > tmp)
			{
				mi = tmp;
				res = j;
			}
		}

		std::cout << res + 1 << std::endl;
	}
	
	return 0;
}
