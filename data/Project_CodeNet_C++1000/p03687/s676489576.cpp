#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char **argv)
{
	string s; cin >> s;
	ll N = (ll)s.size();

	ll res{INF};
	for (auto &w : alphabet)
	{
		ll tmp{0};

		for (ll i = 0; i < N;)
		{
			ll k = i + 1;
			if (w != s[i])
			{
				while (k < N && w != s[k]) {++k;};
				tmp = max(tmp, k-i);
			}
			i = k;
		}

		res = min(res, tmp);
	}
	std::cout << res << std::endl;
}