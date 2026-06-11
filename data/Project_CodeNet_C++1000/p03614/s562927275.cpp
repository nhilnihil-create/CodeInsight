#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			res++;
		if (a[i + 1] == i + 1)
			i++;
		}
	}
	cout << res;
	return 0;
}
