#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, l, a[N];
vector<int> vec;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && a[i - 1] + a[i] >= l)
			vec.push_back(i - 1);
	}
	if (vec.empty()) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for (int i = 1; i < vec[0]; i++)
		cout << i << '\n';
	for (int i = n - 1; i >= vec[0]; i--)
		cout << i << '\n';
}
