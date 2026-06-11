#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100 * 1000 + 20;
int a[N];
int main() {
	int n, x;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	if (n == 2) {
		cout << 1 << "\n" << 2 << "\n" << 3;
		return 0;
	}
	if (x == n) {
		for (int i = 1; i <= 2 * n - 1; i++)
			cout << i << endl;
		return 0;
	}
	if (x <= n) {
		a[x] = a[x + 1] = a[x + 2] = a[x - 1] = 1; 
		int tmp = 0;
		for (int i = 1; i <= 2 * n - 2; i++) {
			if (tmp >= n - 2) {
				break;
			}
			else {
				if (a[i] == 0) {
					cout << i << endl;
					tmp++, a[i] = 1;
				}
			}
		}
		cout << x + 2 << endl << x << endl << x - 1 << endl << x + 1 << endl;
		for (int i = 1; i <= 2 * n - 1; i++) {
			if (a[i] == 0)
				cout << i << endl;	
		}
	}
	else {
		a[x] = a[x - 1] = a[x - 2] = a[x + 1] = 1;
		int tmp = 0;
		for (int i = 1; i <= 2 * n - 1; i++) {
			if (tmp >= n - 2)
				break;
			else {
				if (a[i] == 0) {
					cout << i << endl;
					tmp++, a[i]++;
				}
			}
		}
		cout << x - 2 << endl << x << endl << x + 1 << endl << x - 1 << endl;
		for (int i = 1; i <= 2 * n - 1; i++) {
			if (a[i] == 0)
				cout << i << endl;	
		}
	}
	
	return 0;
}