#include <bits/stdc++.h>

using namespace std;

int main() {

	int k,t;
	cin >> k >> t;
	vector<int> a(t);
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int total = accumulate(a.begin(), a.end(), 0);
	int maxx = a[a.size() - 1];
	int nokori = total- maxx;

	if (nokori -1 >= maxx) {
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << maxx - nokori - 1;
	}

	return 0;
}