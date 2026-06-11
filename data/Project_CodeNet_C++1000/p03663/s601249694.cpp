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
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

ll N;

string to_str(ll n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

bool queryAuto(ll n) {
	bool res = false;
	if (n <= N && to_str(n) <= to_str(N)) res = true;
	if (n > N && to_str(n) > to_str(N)) res = true;
	
	puts(res ? "Y" : "N");
	return res;
}

bool query(ll n) {
	printf("? %lld\n", n);
	fflush(stdout);
	
	if (debug) return queryAuto(n);
	
	string ans; cin >> ans;
	return ans == "Y";
}

int askfl() {
	bool bef;
	
	int one = -1;
	for (ll i = 1, cnt = 0; i <= 100000000000ll; i *= 10, cnt++) {
		bool now = query(i);
		if (i != 1 && bef != now) one = cnt;
		bef = now;
	}
	
	int nine = -1;
	for (ll i = 9, cnt = 0; i <= 100000000000ll; i *= 10, cnt++) {
		bool now = query(i);
		if (i != 9 && bef != now) nine = cnt + 1;
		bef = now;
	}
	
	int res;
	if (one != -1) res = one;
	else res = nine;
	if (res == -1) res = 1;
	
	return res;
}

int main() {
	if (debug) cin >> N;
	
	int keta = askfl();
	
	ll l = 1, r;
	REP(i, keta - 1) l *= 10;
	r = l * 10;
	
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (query(m * 10)) r = m;
		else l = m;
	}
	
	ll ans = r;
	if (query(l * 10)) ans = l;
	
	printf("! %lld\n", ans);
	return 0;
}
