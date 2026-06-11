#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	--N;
	
	ll diff = B - A;
	
	bool ans = false;
	for (ll i = 0; i < N + 1; ++i) {
		ll l = -(N - i) * D + i * C;
		ll r = -(N - i) * C + i * D;
		ans |= l <= diff && diff <= r;
	}
	
	puts([&] {
		return ans;
	}() ? "YES": "NO");
	
	return 0;
}
