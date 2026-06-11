#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string O, E;
	cin >> O >> E;

	int high = max(O.size(), E.size());
	int low = min(O.size(), E.size());

	string ans = "";
	for (int i = 0; i < high; ++i) {
		if (O.size() > E.size()) {
			ans += O[i];
			if (i < E.size()) {
				ans += E[i];
			}
		}
		else {
			if (i < O.size()) {
				ans += O[i];
			}
			ans += E[i];
			
		}
	}

	cout << ans << endl;
	return 0;
}
