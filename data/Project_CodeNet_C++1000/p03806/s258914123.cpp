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

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

template<class T>
bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return false;
	}
	return true;
}

template<class T>
bool chmax(T &a, initializer_list<T> l)
{
	return chmax(a, *max_element(l.begin(), l.end()));
}

template<class T>
bool chmin(T &a, initializer_list<T> l)
{
	return chmin(a, *min_element(l.begin(), l.end));
}


ll dp[50][500][500]{};

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, Ma, Mb; cin >> N >> Ma >> Mb;
	vector<ll> A(N), B(N), C(N);
	REP(i, N) cin >> A[i] >> B[i] >> C[i];

	REP(i, 50)REP(a, 500)REP(b, 500)
	{
		if (a == 0 && b == 0)
			dp[i][a][b] = 0;
		else
			dp[i][a][b] = INF;
	}

	REP(i, N)
	{
		REP(ma, 500)REP(mb, 500)
		{
			chmin(dp[i+1][ma][mb], dp[i][ma][mb]);
			if (ma - A[i] >= 0 && mb - B[i] >= 0) 
				chmin(dp[i+1][ma][mb], dp[i][ma-A[i]][mb-B[i]] + C[i]);
		}
	}

	ll res{INF};
	for (ll i = 1;; i++)
	{
		if (Ma*i >= 500 || Mb*i >= 500) break;
		if (res > dp[N][Ma*i][Mb*i])
		{
			DEBUG(Ma*i);
			DEBUG(Mb*i);
		}
		res = min(res, dp[N][Ma*i][Mb*i]);
	}

	DEBUG(dp[N][3][3]);
	std::cout << ((res == INF) ? -1 : res) << std::endl;
	return 0;
}
