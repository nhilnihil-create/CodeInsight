#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s;
	cin >> t;
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (s == t) {
			x = i;
			break;
		}
		else if (s.length() == 1) {
			x = n;
			break;
		}
		else {
			s = s.substr(1);
			t = t.substr(0, t.length() - 1);
		}
	}
	cout << 2 * n - (n - x) << endl;
}