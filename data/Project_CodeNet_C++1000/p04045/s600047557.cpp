#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main() {

	int n, k; cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < k; i++) {
		int d; cin >> d;
		arr.pb(d);
	}
	int ans = n;
	while (true) {

		int tmp = ans;
		bool check = true;
		while (check && tmp > 0) {
			int rem = tmp % 10;
			if (find(arr.begin(), arr.end(), rem) != arr.end()) {
				check = false;
			}
			if (check) tmp /= 10;
			else {
				ans += 1;
				break;
			}
		}
		if (check) break;
	}
	cout << ans;
	return 0;
}