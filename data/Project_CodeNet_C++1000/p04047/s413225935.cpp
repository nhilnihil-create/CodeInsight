#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(2 * n);

	for (int i = 0; i < 2 * n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int res = 0;

	for (int i = 0; i < 2 * n - 1; i += 2) {
		res += min(nums[i], nums[i + 1]);
	}

	cout << res << endl;
}