#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n, sum, k, p, a[123456], b[123456];
signed main() {
	cin >> n;
	k = n * (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		p += sum / k;
		sum %= k;
		if (i)b[i] = a[i - 1] - a[i];
	}
	b[0] = a[n - 1] - a[0];
	if (sum != 0) {
		cout << "NO\n";
		return 0;
	}
	k = p; p = 0;
	for (int i = 0; i < n; i++) {
		b[i] += k;
		if (b[i] % n != 0 || b[i] < 0) {
			cout << "NO\n";
			return 0;
		}
		p += b[i] / n;
	}
	cout << (p == k ? "YES\n" : "NO\n");
}