#include "bits/stdc++.h"
using namespace std;

int main() {
	int k, s;
	cin >> k >> s;

	int ans = 0;
	int v = min(s, k);

	for (int x = 0; x <= v; x++) {
		for (int y = 0; y <= v; y++) {
			int z = s - x - y;
			if (z <= v && z >= 0)	ans++;
		}
	}
	cout << ans << endl;
}
