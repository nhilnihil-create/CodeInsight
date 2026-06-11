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
	
	int n; cin >> n;
	string s, t; cin >> s >> t;
	int ml = n * 2;

	rep(i, 1, n + 1) {
		if (s.substr(n - i) == t.substr(0, i))
			ml = n * 2 - i;
	}
	
	cout << ml << endl;
}
