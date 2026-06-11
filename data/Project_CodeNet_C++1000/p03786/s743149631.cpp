#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long> summ(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			summ[i] = a[i];
		}
		else {
			summ[i] = summ[i - 1] + a[i];
		}
	}

	int counter = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (summ[i]*2 >= a[i + 1]) {
			counter++;
		}
		else {
			break;
		}
	}
	cout << counter << endl;

	return 0;

}