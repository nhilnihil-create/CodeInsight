#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const bool debug = 0;
//---------------------------------//

int X[112345], Y[1123456];

ll solve(ll W, int *A) {
	ll res = 0;
	FOR(i, 1, W) {
		ll cur = (ll)i * (W - i) % MOD;
		cur = cur * (A[i] - A[i - 1]) % MOD;
		res = (res + cur) % MOD;
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;
	REP(i, N) scanf("%d", X + i);
	REP(i, M) scanf("%d", Y + i);
	
	ll ans = solve(N, X) * solve(M, Y) % MOD;
	cout << ans << endl;
	
	return 0;
}
