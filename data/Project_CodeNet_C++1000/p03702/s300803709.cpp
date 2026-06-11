#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long n, a, b;
	cin >> n >> a >> b;
	vector<long long> h(n);
	for (auto& e : h)cin >> e;
	long long ub = INT32_MAX;
	long long lb = 0;
	while (ub - lb > 1) {
		long long mid = (ub + lb) / 2;
		long long tmp = mid;
		for (auto e : h) {
			tmp -= (max(0LL, (e - b * mid)) + (a - b - 1)) / (a - b);
		}
		if (tmp >= 0) { ub = mid; }
		else { lb = mid; }
	}
	cout << ub << endl;
	return 0;
}