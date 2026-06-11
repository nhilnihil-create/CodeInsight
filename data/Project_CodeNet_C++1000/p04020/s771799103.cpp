#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, a[nm];
long long ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		ans += a[i] / 2;
		if (i < n - 1 && a[i] & 1 && a[i + 1] > 0) {
			ans++;
			a[i + 1]--;
		}
	}
	cout << ans << endl;
}
