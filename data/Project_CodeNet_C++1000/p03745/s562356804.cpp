#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	bool first = false;
	bool up = false;
	bool down = false;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!first) first = true;
		else {
			if (up == false && down == false) {
				if (a.at(i) == a.at(i - 1)) {}
				else if (a.at(i) > a.at(i - 1)) up = true;
				else down = true;
			}
			else if (up == true) {
				if (a.at(i) < a.at(i - 1)) {
					ans++;
					up = false;
					down = false;
				}
			}
			else {
				if (a.at(i) > a.at(i - 1)) {
					ans++;
					up = false;
					down = false;
				}
			}
		}
	}
	ans++;
	cout << ans << endl;
}