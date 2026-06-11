#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--, ans += (a[i] == i);
	for (int i = 0; i < n; i++) {
		if (a[i] == i && a[i + 1] == i + 1)
			ans--, i++;
	}
	cout << ans;
	return 0;
}
