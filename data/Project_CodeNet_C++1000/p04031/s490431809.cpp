#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
		
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int leftA = a[0];
	int rightA = a[n - 1];
	int ans = 2147483647;
	for (int j = leftA; j <= rightA; j++) {
		int tmpSum = 0;
		for (int i = 0; i < n; i++) {
			tmpSum += (a[i] - j) * (a[i] - j);
		}
		ans = min(ans, tmpSum);
	}

	cout << ans << endl;
	return 0;
}