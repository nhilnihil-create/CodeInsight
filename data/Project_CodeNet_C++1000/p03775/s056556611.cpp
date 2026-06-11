#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1e18;

vector<pair<long long, long long>> divisor_pair(long long n) {
	vector<pair<long long, long long>> v;
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) v.emplace_back(i, n/i);
	}
	return v;
}

int digit(long long x) {
	int res = 0;
	while (x > 0) x /= 10, res++;
	return res;
}

int main() {
	long long n;
	cin >> n;
	auto d = divisor_pair(n);
	long long ans = INF;
	for (auto e : d) {
		long long now = max(digit(e.first), digit(e.second));
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}