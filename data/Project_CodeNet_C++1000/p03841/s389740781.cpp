#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, x[N], rem[N], a[N * N];
vector<int> vec;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		a[--x[i]] = i;
		rem[i] = i - 1;
	}
	for (int i = 0; i < n * n; i++)
		if (a[i])
			vec.push_back(a[i]);
	int p = 0;
	for (int num: vec)
		while (rem[num]--) {
			while (a[p])
				p++;
			if (p > x[num])
				break;
			a[p] = num;
		}
	for (int i = 1; i <= n; i++)
		rem[i] = n - i;
	for (int num: vec)
		while (rem[num]--) {
			while (a[p] || p < x[num])
				p++;
			if (p >= n * n)
				break;
			a[p] = num;
		}
	for (int i = 0; i < n * n; i++)
		if (a[i] == 0) {
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
	for (int i = 0; i < n * n; i++)
		cout << a[i] << ' ';
}
