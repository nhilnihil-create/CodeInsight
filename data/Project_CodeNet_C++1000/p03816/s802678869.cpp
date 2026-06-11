#include <bits/stdc++.h>
using namespace std;

const int am = 1e5;
int n, c[am], arr[2];

int main() {
	cin >> n;
	for (int i = 0, a; i < n; i++)
		cin >> a, a--, c[a]++;

	for (int i = 0; i < am; i++)
		if (c[i])
			arr[c[i] & 1]++;
	cout << arr[0] / 2 * 2 + arr[1] << endl;
}
