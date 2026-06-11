#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k[100005];
	cin >> n;
	vector<bool>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
		if (k[i] == i + 1) v[i] = true;
		else v[i] = false;
	}
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i]) {
			count++;
			swap(v[i], v[i + 1]);
			v[i] = false;
			v[i + 1] = false;
		}
	}
	cout << count << endl;
}