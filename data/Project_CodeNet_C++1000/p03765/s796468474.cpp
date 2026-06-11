#include <bits/stdc++.h>

#define int long long

#define For(i,a,b) for (int i = a; i <= (b); ++i)
#define For2(i,a,b) for (int i = a; i >= (b); --i)

#define test int _t; cin >> _t; while (_t--)

#define pii pair<int, int>
#define mpii map<int, int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) (int)a.size()

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF 2147483647
#define EPS 1e-9

//#define FILEOPEN

using namespace std;

int cntS[100005], cntT[100005];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifdef FILEOPEN
		freopen("input.in", "r", stdin);
		freopen("input.out", "w", stdout);
	#endif
	string s, t;
	cin >> s >> t;
	cntS[0] = 0;
	For(i,1,sz(s)) cntS[i] = cntS[i - 1] + (s[i - 1] == 'B' ? 1 : 2); 
	For(i,1,sz(t)) cntT[i] = cntT[i - 1] + (t[i - 1] == 'B' ? 1 : 2); 
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		// a--; b--; c--; d--;
		//cout << cntS[b] - cntS[a - 1] << endl;
		cout << ((cntS[b] - cntS[a - 1] - cntT[d] + cntT[c - 1]) % 3 == 0 ? "YES" : "NO") << endl;
	}
}