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
	ll N; cin >> N;
	string s, res; cin >> s;

	ll cl{0}, cr{0};

	for (auto &e : s)
	{
		if (e == '(')
		{
			++cr;
		}

		if (e == ')')
		{
			if (cr > 0) --cr;
			else ++cl;
		}
		
	}

	REP(x, cl) std::cout << "(";
	std::cout << s;
	REP(x, cr) std::cout << ")";
	std::cout << std::endl;

}
