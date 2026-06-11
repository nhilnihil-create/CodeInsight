#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

#ifdef RICARDO
//Header here
	#include "E:\\Code\\dbg.h"
#else
	#define bug(...) "RICARDO MILOS"
#endif


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

//=================================================CODE=================================================//

signed main()
{	
	fastio;
	cout.precision(10);
	cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#endif
	int n, m; cin >> m >> n;
	vpi prs(m);
	for(auto &e : prs) cin >> e.fi >> e.se;
	sort(rall(prs));

	//siege
	vvi D(n + 1);
	for1(i, n) {
		D[0].pb(i);
		for(int j = i; j <= n; j += i) D[j].pb(i);
	}
	//

	vi bit(n + 1, 0);
	auto up = [&](int i) {
		for(; i <= n; i += i & -i) bit[i]++;
	};
	auto get = [&](int i) {
		int RES = 0;
		for(; i; i -= i & -i) RES += bit[i];
		return RES;
	};

	vi ANS(n + 1, m);
	int cur = 0;
	ford(i, n) {
		while(cur < m && prs[cur].fi > i) {
			up(prs[cur].se);			
			cur++;			
		}

		for(int v : D[i]) {
			int j = i + v;
			ANS[v] -= get(min(j - 1, n));						
		}	
	}

	for1(i, n) cout << ANS[i] << endl;
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}