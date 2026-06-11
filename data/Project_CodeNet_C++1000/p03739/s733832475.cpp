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

ll N;
vector<ll> a;

int main(int argc, char **argv)
{
	cin >> N;
	a.resize(N);
	REP(i, N) cin >> a[i];
	REP(i, N-1)
		a[i+1] += a[i];

	ll res{INF};
	ll pre;
	ll cnt;

	// pattern 1
	pre = 0;
	cnt = 0;
	REP(i, N)
	{
		ll t = a[i] + pre;
		if (i & 1)
		{
			if (t <= 0)
			{
				cnt += -t + 1;
				pre += -t + 1;
			}
		}
		else
		{
			if (t >= 0)
			{
				cnt += t + 1;
				pre -= t + 1;
			}
		}
	}
	res = min(res, cnt);

	// pattern 2
	cnt = 0;
	pre = 0;
	REP(i, N)
	{
		ll t = a[i] + pre;
		if (~i & 1)
		{
			if (t <= 0)
			{
				cnt += -t + 1;
				pre += -t + 1;
			}
		}
		else
		{
			if (t >= 0)
			{
				cnt += t + 1;
				pre -= t + 1;
			}
		}
	}
	res = min(res, cnt);

	std::cout << res << std::endl;
}
