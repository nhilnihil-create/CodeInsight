#include <iostream>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
int main() {
	int n, p; cin >> n;
	int* a = new int[n + 1];
	rep(i, 1, n + 1) {
		cin >> p;
		a[p] = i;
	}
	rep(i, 1, n + 1) cout << n * i << " \n"[i == n];
	rep(i, 1, n + 1) cout << n * (n - i) + a[i] << " \n"[i == n];
	delete[] a;
	return 0;
}
