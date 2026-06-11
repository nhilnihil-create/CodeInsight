#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nm = 1e5;
int n, inf, sup, a[nm];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!i) {
			inf = a[0];
			sup = a[0];
		}
		inf = min(inf, a[i]);
		sup = max(sup, a[i]);
	}

	if (sup - inf > 1) {
		cout << "No" << endl;
		return 0;
	}

	if (inf == sup) {
		cout << (inf == n - 1 || inf <= n / 2 ? "Yes" : "No") << endl;
		return 0;
	}

	int c = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == inf)
			++c;
	cout << (c < sup && sup - c <= (n - c) / 2 ? "Yes" : "No") << endl;
}
