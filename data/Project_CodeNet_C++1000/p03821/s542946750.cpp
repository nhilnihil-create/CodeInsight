#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<long long, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	long long ans = 0, sum = 0, t;
	for (int i = n - 1; i >= 0; i--) {
		t = a[i].second - (a[i].first + sum) % a[i].second;
		t %= a[i].second;

		ans += t;
		sum += t;
	}
	cout << ans << endl;

	return 0;
}