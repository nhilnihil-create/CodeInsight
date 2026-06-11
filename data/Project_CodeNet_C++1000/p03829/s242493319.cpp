#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, x[nm];
long long a, b, rv = 0;

int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n - 1; i++)
		rv += min((x[i + 1] - x[i]) * a, b);
	cout << rv << endl;
}
