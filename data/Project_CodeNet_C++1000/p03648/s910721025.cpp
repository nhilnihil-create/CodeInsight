#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long k;
	cin >> k;
	vector<long long> arr(50, 49 + k / 50);

	for (int i = 0; i < k % 50; ++i) {
		arr[i] += 50;
		for (int j = 0; j < 50; ++j) {
			if (i != j) arr[j]--;
		}
	}

	cout << 50 << '\n';
	for (long long u: arr) cout << u << ' ';
}