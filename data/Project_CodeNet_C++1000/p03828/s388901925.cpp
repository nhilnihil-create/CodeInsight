#include <bits/stdc++.h>
using namespace std;

const int nm = 1e3, mod = 1e9 + 7;
int n, a[nm + 1];

int main() {
	cin >> n;
	for (int i = 2, m; i <= n; i++) {
		m = i;
		for (int j = 2; m > 1 && j * j <= m; j++)
			while (!(m % j))
				m /= j, a[j]++;
		a[m]++;
	}

	long long rv = 1;
	for (int i = 2; i <= nm; i++)
		if (a[i])
			rv = rv * (a[i] + 1) % mod;
	cout << rv << endl;
}
