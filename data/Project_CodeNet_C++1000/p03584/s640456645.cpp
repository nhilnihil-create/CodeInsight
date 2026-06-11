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
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1e9+100;
const ll MOD = 1e9;
const double EPS = 1e-10;
const bool debug = 1;
//------------------------------//

int N, K;
int A[112345], B[112345];

int main() {
	cin >> N >> K;
	REP(i, N) scanf("%d %d", A + i, B + i);
	
	int mabit = 0; // Kの最大bit[0-indexed]
	for (int i = 0; i < 31; i++) if (K >> i & 1) mabit = i;
	REP(i, N) if (A[i] >= (1ll<<(mabit+1))) B[i] = 0;
	
	ll ans = 0;
	
	for (int era = 30; era >= -1; era--) { // Kのeraビット目をサボる
		if (era >= 0 && !(K >> era & 1)) continue;
		
		ll now = 0;
		REP(i, N) {
			bool ng = false;
			;
			for (int j = 30; j > era; j--) {
				if (!(K >> j & 1) && (A[i] >> j & 1)) ng = true;
			}
			if (era >= 0 && (A[i] >> era & 1)) ng = true;
			
			if (ng) continue;
			now += B[i];
		}
		chmax(ans, now);
	}
	
	cout << ans << endl;
	
	return 0;
}
