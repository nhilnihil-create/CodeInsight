#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, c, k;
	cin >> n >> c >> k;
	int t[n];
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	sort(t, t + n);
	
	int ans = 0;

	int start = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (start == -1) {
			ans++;
			start = t[i];
			cnt = 1;
		}
		else {
			cnt++;
			if (cnt > c || t[i] - start > k) {
				start = -1;
				i--;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}
