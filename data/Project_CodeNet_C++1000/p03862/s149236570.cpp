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
	ll N, x; cin >> N >> x;
	vector<ll> A(N); REP(i, N) cin >> A[i];
	
	ll res{0};

	REP(i, N-1)
	{
		if (A[i] + A[i+1] > x)
		{
			ll d = A[i] + A[i+1] - x;
			res += d;

			if (A[i+1] < d)
			{
				A[i] -= (d - A[i+1]);
				A[i+1] = 0;
			}
			else
				A[i+1] -= d;
		}
	}

	std::cout << res << std::endl;
}