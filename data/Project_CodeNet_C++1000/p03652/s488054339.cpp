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

bool to[330][330];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M; cin >> N >> M;
	vector<queue<ll>> A(N);
	vector<bool> is_game(M, true);
	REP(i, N)
	{
		REP(j, M)
		{
			ll a; cin >> a;
			--a;
			A[i].push(a);
		}
	}

	
	ll res{INF};
	while (true)
	{
		vector<ll> join(M, 0);
		REP(i, N)
		{
			while (true)
			{
				ll a = A[i].front();
				if (!is_game[a])
				{
					A[i].pop();
				}
				else
				{
					join[a]++;
					break;
				}

				if (A[i].size() == 0)
					goto exit;
			}
		}

		ll game_i = -1;
		ll ma = 0;
		for (ll i = 0; i < M; ++i)
		{
			if (ma < join[i])
			{
				ma = join[i];
				game_i = i;
			}
		}

		res = min(res, ma);
		is_game[game_i] = false;
	}

 exit:
	std::cout << res << std::endl;	
	
	return 0;
}
