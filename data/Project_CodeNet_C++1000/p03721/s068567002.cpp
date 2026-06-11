#include <bits/stdc++.h>
using namespace std;

int main() {
	uint64_t n,k;
	cin >> n >> k;
	vector<vector<uint64_t>> nums(n,vector<uint64_t>(2));

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		nums.at(i).at(0) = a;
		nums.at(i).at(1) = b;
	}

	sort(nums.begin(), nums.end());

	/*
	cout << "nums" << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums.at(i).at(0) << " " << nums.at(i).at(1) << endl;
	}
	*/

	uint64_t temp = 0;
	uint64_t ans = 0;
	for (int i = 0; i < nums.size(); i++) {	
		if (temp >= k) {
			ans = nums.at(i-1).at(0);
			break;
		}
		temp += nums.at(i).at(1);
		if (i == nums.size() - 1) { ans = nums.at(i).at(0); }
	}
	cout << ans << endl;
}