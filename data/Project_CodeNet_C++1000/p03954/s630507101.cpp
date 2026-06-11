#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, a[N];
bool b[N];

bool nbig(int x) {
	for (int i = 1; i < 2 * n; i++) {
		if (a[i] <= x)
			b[i] = 1;
		else
			b[i] = 0;
	}
	if (b[n] == b[n - 1] || b[n] == b[n + 1])
		return b[n];
	int l = 0, r = 2 * n;
	for (int i = 1; i + 1 < 2 * n; i++) {
		if (b[i] == b[i + 1]) {
			if (i < n)
				l = i + 1;
			else
			if (r == 2 * n)
				r = i;
		}
	}
	if (r == 2 * n && !l) {
		return (b[n] + n + 1) % 2;
	}	
	if (n - l < r - n)
		return b[l];
	else
		return b[r];
}

int main() {
	cin >> n;
	for (int i = 1; i < 2 * n; i++)
		cin >> a[i];
	int l = 0, r = 2 * n;
	while (r - l > 1) {
		int md = (r + l) / 2;
		if (nbig(md))
			r = md;
		else
			l = md;
	}
	cout << r;

	return 0;
}
