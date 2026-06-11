#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b);
int main() {
	/*
	int n;
	cin >> n;
	int L[200];
	int i,j,c;
	for (i = 0; i < 2 * n; i++) {
		cin >> L[i];
	}
	//ソート
	for (i = 0; i < 2 * n - 1; i++) {
		for (j = 0; j < 2 * n -1 - i; j++) {
			if (L[j] < L[j + 1]) {
				c = L[j];
				L[j] = L[j + 1];
				L[j + 1] = c;
			}
		}
	}
	c = 0;
	for (i = 1; i < 2 * n; i = i + 2) {
		c = c + L[i];
	}
	cout << c;
	return 0;
	*/
	long long int n, x;
	cin >> n;
	cin >> x;

	cout << 3 * n - 3 * gcd(n, x);
	return 0;
}

long long int gcd(long long int a, long long int b) {

	long long int aa, bb,cc;
	if (a > b) {
		aa = a;
		bb = b;
	}
	else {
		aa = b;
		bb = a;
	}

	if (aa % bb == 0) {
		return bb;
	}
	else {
		return gcd(bb, aa % bb);
	}


}