#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <map>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

ll ans[10];
pair<ll, ll> g[100005];
map<pair<ll, ll>, bool> m;
ll H, W, N;

int num(ll h, ll w)
{
	int n = 0;

	h--; w--;
	REP(i, 3)
	{
		ll th = h + i;
		if (th < 0 || th >= H)return -1;
		REP(j, 3)
		{
			ll tw = w + j;
			if (tw < 0 || tw >= W)return -1;

			pair<ll, ll> p(th, tw);
			if (m[p])
			{
				n++;
			}
		}
	}

	return n;
}

int main()
{
	cin >> H >> W >> N;
	REP(i, N)
	{
		cin >> g[i].first >> g[i].second;
		g[i].first--; g[i].second--;
	}

	sort(g, g + N, [](pair<ll, ll> a, pair<ll, ll> b) {return a.first == b.first ? a.second < b.second:a.first < b.first; });

	REP(i, 10)
	{
		ans[i] = 0;
	}
	ans[0] = (H - 2)*(W - 2);

	REP(i, N)
	{
		pair<ll, ll> p = g[i];
		ll h = p.first - 1;
		ll w = p.second - 1;
		REP(j, 3)
		{
			ll th = h + j;
			if (th < 0 || th >= H)continue;
			REP(k, 3)
			{
				ll tw = w + k;
				if (tw < 0 || tw >= W)continue;

				int n = num(th, tw);
				if (n == -1)continue;
				ans[n]--;
				ans[n + 1]++;
			}
		}
		m[p] = true;
	}

	REP(i, 10)
	{
		cout << ans[i] << endl;
	}
	return 0;
}