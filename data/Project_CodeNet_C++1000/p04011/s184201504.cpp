#include <iostream>
using namespace std;
int main() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (k - 1 < i)
			ans += y;
		else
			ans += x;

	}
	cout << ans << "\n";
}