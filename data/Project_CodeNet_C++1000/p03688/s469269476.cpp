#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, mx = -1, mn = 1e6;
map<int, int> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// If range > 1, then no.
	// There are bigger number amount of colors
	// Need EXACTLY smaller number amount of smaller numbers, is that true?
	// Not true, 4 4 4 4 3 3 -> 3 3 0 0 1 2, basically just make sure that smaller number + 
	// larger num / 2 > larger number
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		++m[a];
		mx = max(mx, a);
		mn = min(mn, a);
	}
	
	if (mx - mn > 1) cout << "No";
	else {
		if (mx == mn) {
			if (n == mx + 1 || n >= mx * 2) cout << "Yes";
			else cout << "No";
		} else {
			if (m[mn] > mn) cout << "No";
			else if (m[mn] + m[mx] / 2 >= mx) cout << "Yes";
			else cout << "No";
		}
	}
}
