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
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;


int main() {
	int n;
	cin >> n;
	VI  t(n), a(n), v;
	REP(i, n) cin >> t[i];
	REP(i, n)cin >> a[i];
	if (a[0] != t[n-1]) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	FOR(i, 1, n - 1) {
		if (t[i - 1] == t[i] && a[i] == a[i + 1]) {
			ans *= min(t[i], a[i]);
			ans %= mod;
		}
		else if (t[i - 1] < t[i] && a[i] > a[i + 1] && t[i] != a[i])ans = 0;
		else if (t[i - 1] == t[i] && a[i] > a[i + 1] && t[i] < a[i])ans = 0;
		else if (t[i - 1] < t[i] && a[i] == a[i + 1] && t[i] > a[i])ans = 0;
	}
	cout << ans << endl;

}