#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, k;
	cin >> n >> k;
	vector<vector<int64_t>>vec(n, vector<int64_t>(2));
	for (int i = 0; i < n; i++) cin >> vec.at(i).at(0) >> vec.at(i).at(1);
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		int64_t a = vec.at(i).at(0);
		int64_t b = vec.at(i).at(1);
		if (k > b)k -= b;
		else {
			cout << a << endl;
			return 0;
		}
	}
}
