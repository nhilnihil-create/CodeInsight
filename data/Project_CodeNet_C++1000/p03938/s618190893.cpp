#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> p(N);
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		a[i] = 20020 * (i + 1);
		b[i] = 20020 * (N - i);
	}
	for (int i = 0; i < N; ++i)
		a[p[i] - 1] += i;
	for (auto ai : a)
		cout << ai << " ";
	cout << endl;
	for (auto bi : b)
		cout << bi << " ";
	cout << endl;
	return 0;
}