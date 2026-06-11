#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;

using namespace std;




int main() {
	
	ll n, a, b;
	cin >> n >> a >> b;
	VLL h(n);
	REP(i, n)cin >> h[i];
	ll l = 1;
	ll r = 1000000000;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		ll c = m;
		VLL v = h;
		REP(i, n) {
			v[i] -= b * m;
			if (v[i] > 0) {
				c -= (v[i] + a - b - 1) / (a - b);
			}
		}
		if (c>=0)r = m;
		else l = m;
	}
	int ans = INF;
	for (int i = l; i <= r; i++) {
		ll c = i;
		VLL v = h;
		REP(j, n) {
			v[j] -= b * i;
			if (v[j] > 0) {
				c -= (v[j] + a - b - 1) / (a - b);
			}
		}
		if (c >= 0)ans = min(ans, i);
	}
	cout << ans << endl;
	return 0;
}