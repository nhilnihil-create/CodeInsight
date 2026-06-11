#include <bits/stdc++.h>
using namespace std;

const int N = 202;

int n, ans, a[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	for (int i = 0; i < 2 * n; i += 2)
		ans += a[i];
	cout << ans;
}
