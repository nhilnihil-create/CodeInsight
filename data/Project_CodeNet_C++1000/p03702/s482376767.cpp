#include <iostream>
#include <vector>
using namespace std;

int n, a, b;

bool can(vector<int>& arr, long long t) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		long long rem = arr[i] - t * b;
		if (rem > 0) ret += (rem - 1) / (a - b) + 1;
	}
	return ret <= t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	vector<int> arr(n);
	int low = 0, high = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}

	high = high / b + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (can(arr, mid)) high = mid;
		else low = mid;
	}

	cout << high;
}