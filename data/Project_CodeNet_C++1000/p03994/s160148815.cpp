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
	string s; cin >> s;
	ll K; cin >> K;
	ll N = (ll)s.size();
	vector<ll> diff(N);

	REP(i, N)
	{
		if (s[i] == 'a') diff[i] = 0;
		else
			diff[i] = 26 - abs('a' - s[i]);
		// std::cout << diff[i] << std::endl;
	}

	string res;
	REP(i, N)
	{
		if (diff[i] <= K)
		{
			res += 'a';
			K -= diff[i];
		}
		else
		{
			res += s[i];
		}
	}

	if (K > 0)
	{
		res.back() += (K % 26);
	}
	std::cout << res << std::endl;
}