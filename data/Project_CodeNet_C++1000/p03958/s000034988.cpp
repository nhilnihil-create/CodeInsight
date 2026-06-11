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
	ll K, T; cin >> K >> T;
	vector<ll> A(T);
	REP(i, T) cin >> A[i];

	sort(ALL(A), greater<ll>());
	ll m = A.front();
	ll sum = accumulate(next(A.begin()), A.end(), 0ll);
	std::cout << max(m - sum - 1, 0ll) << std::endl;
}