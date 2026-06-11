#include <iostream>
#define int long long
using namespace std;

int n;
int A[100000];
int a[100000];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> A[i];
	for (i = 0; i < n; i++) a[i] = A[(i + 1) % n] - A[i];
	
	int sumA = 0;
	for (i = 0; i < n; i++) {
		sumA += A[i];
	}
	int wa = n * (n + 1) / 2;
	if (sumA % wa != 0) { cout << "NO" << endl; return 0; }
	int T = sumA / wa;
	
	for (i = 0; i < n; i++) {
		a[i] -= T;
	}
	
	int ssum = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > 0) { cout << "NO" << endl; return 0; }
		int b = -a[i];
		if (b % n != 0) { cout << "NO" << endl; return 0; }
		ssum += b / n;
	}
	
	if (ssum != T) { cout << "NO" << endl; return 0; }
	
	cout << "YES" << endl;
	return 0;
}