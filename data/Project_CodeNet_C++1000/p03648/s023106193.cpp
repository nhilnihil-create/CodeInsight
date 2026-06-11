#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL MOD = 1000000007LL;
LL a[50];
int main() {
	LL K;
	cin >> K;
	LL q = K / 50, r = K % 50;
	for (int i = 0; i < 50; i++) {
		a[i] = i + q;
		if (i < r) a[i] += 50 - (r - 1);
		else a[i] -= r;
	}
	cout << 50 << endl;
	cout << a[0];
	for (int i = 1; i < 50; i++) {
		cout << " " << a[i];
	}
	cout << endl;
}