#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 1, cnt_max = 0;
	for (int i = n; i > 0; i--) {
		int t = i, cnt = 0;
		while (t % 2 == 0) {
			t /= 2; cnt++;
		}
		if (cnt_max < cnt) {
			cnt_max = cnt;
			ans = i;
		}
	}
	cout << ans << endl;

	return 0;
}