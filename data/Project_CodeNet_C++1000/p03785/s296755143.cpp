#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, c, k;
	cin >> n >> c >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int t = a[0];
	int ans = 1;
	int c_ = 1;
	for (int i = 1; i < n; i++) {
		if (t + k >= a[i]) {
			if (c_ == c) {
				c_ = 1;
				t = a[i];
				ans++;
			} else {
				c_++;
			}
		} else {
			t = a[i];
			ans++;
			c_ = 1;
		}
	}
	cout << ans << endl;

	return 0;
}