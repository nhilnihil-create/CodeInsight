#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());

	long long ans1 = 0, ans2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			if (ans1 == 0) {
				ans1 = a[i];
				i++;
			} else if (ans2 == 0) {
				ans2 = a[i];
				
				cout << ans1 * ans2 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;

	return 0;
}