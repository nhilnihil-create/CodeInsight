#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	int cnt4 = 0;
	int cnt2 = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a % 4 == 0) cnt4++;
		else if (a % 2 == 0) cnt2++;
		else cnt++;
	}
	string ans = "No";
	if (n % 2 != 0) {
		int tmp = 0;
		if (cnt2 % 2 != 0) {
			tmp = cnt2 - 1;
		}
		else {
			tmp = cnt2;
		}
		n -= tmp;
		if (n / 2 <= cnt4 + 1) {
			ans = "Yes";
		}
	}
	else { // n % 2 == 0
		int tmp = 0;
		if (cnt2 % 2 != 0) {
			tmp = cnt2 - 1;
		}
		else {
			tmp = cnt2;
		}
		n -= tmp;
		if (n / 2 <= cnt4) {
			ans = "Yes";
		}
	}
	cout << ans << endl;
    return 0;
}