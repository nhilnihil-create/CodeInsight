#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<numeric>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long h, w, n;
	cin >> h >> w >> n;
	unordered_map<long long, int> kuro;
	long long a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a--; b--;
		for (long long j = max(1LL, a - 1); j <= min(a + 1, h - 2); j++) {
			for (long long k = max(1LL, b - 1); k <= min(b + 1, w - 2); k++) {
				kuro[j*w+k]++;
			}
		}
	}
	vector<long long> ans(10);
	for (auto& e : kuro) {
		ans[e.second]++;
	}
	ans[0] = (h - 2)*(w - 2);
	for (int i = 1; i < 10; i++) {
		ans[0] -= ans[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}