#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort (v.begin(), v.end());
	if (v.back() - v[0] > 1) {
		cout << "No";
		return 0;
	}
	if (v.back() == v[0]) {
		if (n == v[0] + 1 || n >= v[0] * 2) {
			cout << "Yes";
		}
		else
			cout << "No";
		return 0;
	}
	int k = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == v[0])
			k = i;
	}
	k++;
	int t = v[0] - k + 1;
	if (t <= 0) {
		cout << "No";
		return 0;
	}
	if (n - k >= 2 * t) {
		cout << "Yes";
	}
	else
		cout << "No";
	return 0;
}
