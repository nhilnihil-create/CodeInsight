#include <iostream>
using namespace std;
int main() {
	int d[3], ans = 0, temp, temp2;
	bool flag = true, db[3];
	cin >> d[0] >> d[1] >> d[2];
	if (d[0] == d[1] && d[1] == d[2]) {
		flag = false;
	}
	if ((d[0] % 2 != 0 || d[1] % 2 != 0) || d[2] % 2 != 0) {
		goto FINISH;
	}
	for (int i = 0; i < 3 && flag; i++) {
		temp = d[i];
		while (temp % 2 == 0) {
			temp /= 2;
		}
		if (temp == 1) {
			db[i] = true;
		}
		else {
			db[i] = false;
		}
	}
	if (flag && db[0] && db[1] && db[2]) {
		flag = false;
	}
	if (flag) {
		while ((d[0] % 2 == 0 && d[1] % 2 == 0) && d[2] % 2 == 0) {
			temp = d[0] / 2;
			temp2 = d[1] / 2;
			d[0] = temp2 + d[2] / 2;
			d[1] = temp + d[2] / 2;
			d[2] = temp + temp2;
			ans++;
		}
	}
	if (flag) {
	FINISH:
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
}