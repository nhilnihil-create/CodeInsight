//In the name of GOD
//SMani24
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void write_output(int cnt) {
	int sum = 0;
	int tf = 0, f = -1;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (a[i] % 2) {
			tf++;
			f = a[i];
		}
	}
	if ((sum - n) % 2) {
		if (cnt % 2)
			cout << "Second" << endl;
		else
			cout << "First" << endl;
		exit(0);
	}
	else if (tf == 1 && f != 1) {
		int gcd = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2)
				a[i]--;
			gcd = __gcd(gcd, a[i]);
		}
		for (int i = 0; i < n; i++)
			a[i] /= gcd;
		write_output(cnt + 1);
	}
	if (cnt % 2)
		cout << "First\n";
	else
		cout << "Second\n";
	exit(0);
}

int32_t main() {
	read_input(), write_output(0);
	return 0;
}
