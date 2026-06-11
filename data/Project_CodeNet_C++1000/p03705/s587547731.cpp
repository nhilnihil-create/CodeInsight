#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, a, b; cin >> n >> a >> b;
	if (n == 1) {
		cout << (a == b ? 1 : 0) << endl;
	} else {
		if (a <= b) {
			ll lo = a * (n - 1) + b;
			ll hi = a + b * (n - 1);
			cout << (hi - lo + 1) << endl;
		} else {
			cout << 0 << endl;
		}
	}
}
