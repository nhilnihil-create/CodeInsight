#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<bool> vec(n + 1, false);
	vec[1] = true;

	vector<int> vec2(n + 1 , 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		vec2[y] += 1;
		vec2[x] -= 1;

		if (vec[x]) {
			if (vec2[x] == 0) vec[x] = false;
			vec[y] = true;
		}
	}

	int ans = 0;
	for (auto e : vec) {
		if (e)	ans++;
	}

	cout << ans << endl;
}