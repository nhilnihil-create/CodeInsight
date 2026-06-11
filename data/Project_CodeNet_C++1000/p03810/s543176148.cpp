/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1001;
int n, a[N];

void solve(int cnt) {
	int odd = 0, odd_n = -1;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (a[i] % 2) {
			odd++;
			odd_n = a[i];
		}
	}
	if ((sum - n) % 2) {
		if (cnt % 2)
			cout << "Second\n";
		else
			cout << "First\n";
		exit(0);
	}
	else if (odd == 1 && odd_n != 1) {
		int gcd = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) 
				a[i]--;
			gcd = __gcd(gcd, a[i]);
		}
		for (int i = 0; i < n; i++) 
			a[i] /= gcd;
		solve(cnt + 1);
	}
	if (cnt % 2) 
		cout << "First\n";
	else
		cout << "Second\n";
	exit(0);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	solve(0);
}