#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;


int main() {

	ll n;
	cin >> n;

	VLL x(n+1);
	REP(i, n)cin >> x[i];
	x[n] = INFL;
	ll l;
	cin >> l;
	VVLL d(n + 5, VLL(30, 0));

	REP(i, n) {
		d[i][0] = upper_bound(ALL(x), x[i] + l) - x.begin();
		d[i][0]--;
	}
	
	REP(j, 29)REP(i, n) {
		d[i][j + 1] = max(d[d[i][j]][j], d[i][j]);
	}

	

	ll q;
	cin >> q;
	REP(i, q) {
		ll a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		a--;
		b--;

		ll ans = 0;

		for (int i = 29; i >= 0; i--) {
			if (d[a][i] < b) {
				if (d[a][i] == 0)continue;
				a = d[a][i];
				ans += 1LL << i;
			}
		}
		ans++;
		cout << ans << endl;

	}

	return 0;


}

