#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
int getAns(int fna = 0) {
	int od = 0, ev = 0, gd = 0, bad = 0;
	for (int i = 0; i < n; i++)
		od += (a[i] % 2), ev += 1 - (a[i] % 2);
	if (ev % 2 == 1)
		return fna + 1;
	if (od > 1)
		return fna;
	for (int i = 0; i < n; i++)
		a[i] -= (a[i] % 2), bad += (a[i] == 0) , gd = __gcd(gd, a[i]);
	if (bad)
		return 0 + fna;
	for (int i = 0; i < n; i++)
		a[i] /= gd;
	return getAns(1) + fna;
}	
int main() {
	cin >> n;
	if (n == 1) {
		cout << "Second";
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (getAns() % 2 == 1)
		cout << "First";
	else
		cout << "Second";
	return 0;
}