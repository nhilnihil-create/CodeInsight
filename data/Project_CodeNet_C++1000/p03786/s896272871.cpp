#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<long long> b = a;
	for (int i = 1; i < n; i++) {
		b[i] += b[i - 1];
	}

	for (int i = n - 1; i > 0; i--) {
		if (b[i - 1] * 2 < a[i]) {
			cout << n - i << endl;
			return 0;
		}
	}
	cout << n << endl;

	return 0;
}