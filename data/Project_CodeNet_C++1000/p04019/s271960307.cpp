#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	cin.exceptions(cin.failbit);

	string st; cin >> st;
	int n = 0, w = 0, s = 0, e = 0;
	for (char c : st) {
		if (c == 'N') n++;
		if (c == 'W') w++;
		if (c == 'S') s++;
		if (c == 'E') e++;
	}
	n = !!n, w = !!w, s = !!s, e = !!e;
	if ((n ^ s) || (w ^ e)) cout << "No" << endl;
	else cout << "Yes" << endl;
}
