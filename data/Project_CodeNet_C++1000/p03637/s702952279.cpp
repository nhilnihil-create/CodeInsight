#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	
	int a;
	int cnt_4 = 0;
	int cnt_2 = 0;
	int cnt_odd = 0;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 4 == 0) cnt_4++;
		else if (a % 2 == 0) cnt_2++;
		else cnt_odd++;
	}

	string ans = "No";

	int tmp = n - (2 * cnt_4 + 1);

	if (n <= 0) {
		ans = "Yes";
	}
	else {
		if (tmp % 2 == 0) {
			if (tmp <= cnt_2) ans = "Yes";
		}
		else {
			if (tmp < cnt_2) ans = "Yes";
		}
	}

	cout << ans << endl;
	return 0;
}