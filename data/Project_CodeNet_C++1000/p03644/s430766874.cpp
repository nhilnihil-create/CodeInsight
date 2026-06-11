#include<iostream>
using namespace std;
int main() {
	int n, cnt = 0, mx = 0, ans = 1; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x % 2 == 0) {
			x /= 2;
			cnt++;
		}
		if (mx < cnt) {
			mx = cnt;
			ans = i;
		}
		cnt = 0;
	}
	cout << ans << endl;
}