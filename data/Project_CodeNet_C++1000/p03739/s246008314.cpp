#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;

	long long ans1 = 0, ans2 = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (i % 2 == 0 && sum >= 0) {			
			ans1 += sum + 1;
			sum = -1;
		}
		else if (i % 2 == 1 && sum <= 0) {
			ans1 += -sum + 1;
			sum = 1;
		}
	}

	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (i % 2 == 1 && sum >= 0) {
			ans2 += sum + 1;
			sum = -1;
		}
		else if (i % 2 == 0 && sum <= 0) {
			ans2 += -sum + 1;
			sum = 1;
		}
	}
	cout << min(ans1, ans2) << endl;

	return 0;
}