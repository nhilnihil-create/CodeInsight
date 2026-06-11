#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int main() {
	ll x = 1;
	int t;
	for (t = 0; t < 12; t++) {
		cout << "? " << x << endl;
		string ans; cin >> ans;
		if (ans == "N") break;
		x = x * 10;
	}
	if (t == 12) {
		for (t = 12; t >= 1; t--) {
			cout << "? " << string(t, '9') << endl;
			string ans; cin >> ans;
			if (ans == "N") { t++; break; };
		}
		if (!t) t = 1;
	}
	string pre;
	while (t--) {
		int lb = -1, ub = 9;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			string s = pre;
			s.pb('0' + mid);
			while (s.size() < 16) s.pb('9');
			if (s[0] == '0') {
				lb = mid;
				continue;
			}
			cout << "? " << s << endl;
			string ans; cin >> ans;
			if (ans == "Y") ub = mid;
			if (ans == "N") lb = mid;
		}
		pre.pb('0' + ub);
	}
	cout << "! " << pre << endl;
}
