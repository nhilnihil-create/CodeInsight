#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;
	int ans = 0, status = 0;
	for (int i = 0; i < n - 1; i++) {
		if (status == 0) {
			if (a[i + 1] - a[i] > 0)status = 1;
			else if (a[i + 1] - a[i] < 0)status = 2;
		}
		if (status == 1 && a[i + 1] - a[i] < 0) {
			ans++; status = 0;
		}
		else if (status == 2 && a[i + 1] - a[i] > 0) {
			ans++; status = 0;
		}
	}
	cout << ans+1 << endl;

	return 0;
}