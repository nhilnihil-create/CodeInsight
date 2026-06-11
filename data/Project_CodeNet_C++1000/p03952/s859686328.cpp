#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int a[N], b[N], p = 1, mrk[N];

int main() {
	int n, x;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;
	if (n == 2) {
		cout << "1 2 3";
		return 0;
	}
	if (x == 2) {
		a[n - 1] = x + 2;
		a[n] = x;
		a[n + 1] = x - 1;
		a[n + 2] = x + 1;
		mrk[x - 1] = mrk[x + 2] = mrk[x] = mrk[x + 1] = 1;
	}
	else {
		a[n - 1] = x - 2;
		a[n] = x;
		a[n + 1] = x + 1;
		a[n + 2] = x - 1;
		mrk[x - 1] = mrk[x - 2] = mrk[x] = mrk[x + 1] = 1;		
	}
	
	for (int i = 1; i <= 2 * n - 1; i++) {
		if (a[i] > 0)
			continue;
		while (mrk[p])
			p++;
		a[i] = p;
		mrk[p] = 1;		
	}
	for (int i = 1; i <= 2 * n - 1; i++)
		cout << a[i] << endl;
	return 0;
}










