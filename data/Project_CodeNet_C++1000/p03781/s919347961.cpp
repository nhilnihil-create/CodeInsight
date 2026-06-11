#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x; cin >> x;
	for (int i = 1; ; i++) {
		long long now = (long long)(i + 1) * i / 2;
		if (now >= x) {
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}

