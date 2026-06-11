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
	
	ll a, b; cin >> a >> b;
	
	if (a <= 0 && 0 <= b) {
		cout << "Zero" << endl;
		return 0;
	}

	ll cntneg = 0;
	if (a < 0) {
	if (b < 0)
		cntneg = b - a + 1;
	else
		cntneg = 0 - a;
	}

	if (cntneg % 2 == 0) {
		cout << "Positive" << endl;
	} else {
		cout << "Negative" << endl;
	}
}
