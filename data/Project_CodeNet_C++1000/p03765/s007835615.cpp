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
	string s, t; cin >> s >> t;
	vi prefs(s.size()), preft(t.size());
	prefs[0] = s[0] - 'A' + 1;
	for1(i, s.size() - 1) prefs[i] = prefs[i - 1] + (s[i] - 'A' + 1);
	preft[0] = t[0] - 'A' + 1;
	for1(i, t.size() - 1) preft[i] = preft[i - 1] + (t[i] - 'A' + 1);

	int q; cin >> q; while(q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		int cnts = prefs[b] - (a ? prefs[a - 1] : 0);
		int cntt = preft[d] - (c ? preft[c - 1] : 0);

		int delt = cnts - cntt;
		cout << (delt % 3 ? "NO" : "YES") << endl;
	}
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}