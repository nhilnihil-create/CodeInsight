#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

vector<int> v[26];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s; read(s);
	
	rep(i, 0, 26) v[i].push_back(-1);
	rep(i, 0, sz(s)) v[s[i] - 'a'].push_back(i);
	rep(i, 0, 26) v[i].push_back(sz(s));

	int ans = 0x3f3f3f3f;

	rep(i, 0, 26) {
		int lans = 0;
		rep(j, 0, sz(v[i]) - 1)
			chmax(lans, v[i][j + 1] - v[i][j]);
		chmin(ans, lans - 1);
	}

	die(ans);
}
