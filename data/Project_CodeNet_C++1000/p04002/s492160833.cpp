#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

using P = pair<int, int>;

int main() {
	ll H, W, N;
	cin >> H >> W >> N;
	map<P, int> mp;
	vector<int> a(N);
	vector<int> b(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < N; i++) {
		for (int x = b[i] - 1; x <= b[i] + 1; x++) {
			for (int y = a[i] - 1; y <= a[i] + 1; y++) {
				if ((x < 1) || (x > W) || (y < 1) || (y > H)) continue;

				mp[P(x, y)]++;
			}
		}
	}

	vector<ll> res(10, 0);
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int x = it->first.first, y = it->first.second;
		if ((x <= 1) || (x >= W) || (y <= 1) || (y >= H)) continue;

		res[it->second]++;
	}

	ll psum = 0;
	for (int i = 1; i < res.size(); i++) {
		psum += res[i];
	}
	res[0] = (H - 2) * (W - 2) - psum;

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}
