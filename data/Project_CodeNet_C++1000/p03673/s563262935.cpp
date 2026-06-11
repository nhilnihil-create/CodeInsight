#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
	int n,i;
	cin >> n;
	vector<int> a(n), b;
	rep(i, n) {
		cin >> a[i];
	}
	
	for (i = n - 1; i >= 0; i -= 2) {
		b.push_back(a[i]);
	}
	if (n % 2 == 0)	i = 0;
	else			i = 1;
	for (; i < n; i += 2) {
		b.push_back(a[i]);
	}
	rep(i, n-1) {
		cout << b[i] << " ";
	}
	cout << b[n - 1] << endl;
	return 0;
}