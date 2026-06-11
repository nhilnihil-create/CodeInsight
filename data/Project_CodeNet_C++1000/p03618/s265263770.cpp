#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

string S;
int main(int argc, char **argv)
{
	cin >> S;
	ll N = S.size();
	ll res{(N*(N-1))/2+1};

	vector<ll> cnt(26, 0);
	for (auto &e : S)
	{
		++cnt[e-'a'];
	}

	ll tmp{0};
	REP(i, 26)
	{
		res -= cnt[i] * (cnt[i]-1) / 2;
	}

	std::cout << res << std::endl;
}
