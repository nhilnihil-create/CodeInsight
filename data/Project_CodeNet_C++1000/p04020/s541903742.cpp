#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long sum = 0;
	long long streak = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			streak += a[i];
		} else {
			sum += streak / 2;
			streak = 0;
		}
	}
	sum += streak / 2;
	cout << sum << endl;

	return 0;
}