#include<bits/stdc++.h>
using namespace std;
int main() {
	long long H, W, N; cin >> H >> W >> N;
	struct Sqare {
		long long a, b;
	};
	vector<Sqare>  sq(N);
	for (int i = 0; i < N; i++) {
		cin >> sq[i].a >> sq[i].b;
		sq[i].a--;
		sq[i].b--;
	}
	vector<long long > ans(10, 0);
	map<int, map<int, int >> mp;
	ans[0] = (H - 2)*(W - 2);
	auto isOK = [&](int a, int b) {
		return 0 <= a && 0 <= b && a + 3 <= H && b + 3 <= W;
	};
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				if (isOK(sq[i].a - k, sq[i].b - l)) {
					mp[sq[i].a - k][sq[i].b - l]++;
				}
			}
		}
	}
	for (auto itr = mp.begin(); itr != mp.end(); itr++) {
		for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++) {
			ans[itr2->second]++;
			ans[0]--;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}