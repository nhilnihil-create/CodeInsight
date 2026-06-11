#include<iostream>
using namespace std;
long long n, a[100000], b1, b2;
long long G(long long p1, long long p2) { if (p2 == 0)return p1; return G(p2, p1%p2); }
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i]; if (a[i] % 2 == 1)b1++; else b2++; }
	int turn = 0;
	while (b1 == 1 && b2 % 2 == 0) {
		bool flag = false;
		for (int i = 0; i < n; i++) { if (a[i] % 2 == 1) { a[i]--; if (a[i] == 0)flag = true; } }
		if (flag == true)break;
		long long gcd = a[0]; for (int i = 1; i < n; i++)gcd = G(gcd, a[i]);
		for (int i = 0; i < n; i++) { a[i] /= gcd; }
		b1 = 0; b2 = 0;
		for (int i = 0; i < n; i++) { if (a[i] % 2 == 0)b2++; else b1++; }
		turn ^= 1;
	}
	while (true) {
		if (b2 % 2 == 1) { b2--; b1++; }
		else {
			if (turn == 0)cout << "Second" << endl;
			else cout << "First" << endl;
			break;
		}
		turn ^= 1;
	}
	return 0;
}