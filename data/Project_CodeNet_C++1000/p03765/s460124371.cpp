// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 1e5 + 5;

int PS[N][2];

int main() {
 
	sync;

	string s, t; cin >> s >> t;
	for (int i = 0; i < sz(s); i++) PS[i + 1][0] = PS[i][0] + s[i] - 'A' + 1;
	for (int i = 0; i < sz(t); i++) PS[i + 1][1] = PS[i][1] + t[i] - 'A' + 1;

	int q; cin >> q;
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d; a--, c--;
		int x = (PS[b][0] - PS[a][0]) % 3, y = (PS[d][1] - PS[c][1]) % 3;
		cout << (x == y ? "YES" : "NO") << endl;
	}

	return 0;
}
