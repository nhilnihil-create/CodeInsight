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
	int n; cin >> n;
	ll sum = 0;
	rep(i, 0, n) {
		int t; cin >> t;
		sum += t;
	}
	if (sum % 2 == 0) cout << "YES" << endl; else cout << "NO" << endl;
}
