#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void err()
{
	std::cout << "No"<< std::endl;
	exit(0);
}

int main(int argc, char **argv)
{
	ll H, W; cin >> H >> W;
	vector<ll> cnt(26, 0);

	REP(_, H)
	{
		string s; cin >> s;
		for (char c : s)
		{
			cnt[c-'a']++;
		}
	}


	if ((H*W)&1)
	{
		REP(i, 26)
		{
			if (cnt[i]&1)
			{
				cnt[i]--;
				break;
			}
		}
	}

	REP(i, 26)
	{
		if (cnt[i]&1)
		{
			err();
		}
	}

	ll n2{0};
	if (H&1) n2 += W/2;
	if (W&1) n2 += H/2;

	ll ex2{0};
	REP(i, 26)
	{
		if (cnt[i] % 4 == 2)
			++ex2;
	}

	if (ex2 > n2) err();
	std::cout << "Yes" << std::endl;
}
