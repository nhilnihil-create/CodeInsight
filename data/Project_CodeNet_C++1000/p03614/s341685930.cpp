#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int main() {
	int n, ans = 0;
	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == i) {
			x++;
		}
		else {
			ans += x - x / 2;
			x = 0;
		}
	}
	ans += x - x / 2;
	cout << ans << endl;
	return 0;
}
