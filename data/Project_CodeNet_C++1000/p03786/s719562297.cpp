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
	vector<ll> A(N);
	vector<ll> sum(N+1, 0);
	REP(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	REP(i, N) sum[i+1] = sum[i] + A[i];


	ll j{0};
	REP(i, N)
	{
		if (sum[i]*2 < A[i])
			j = i;
	}
	std::cout << N - j << std::endl;
}
