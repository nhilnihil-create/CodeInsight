#include <iostream>
#define int long long
using namespace std;

int f(int a, int b) {
	if (a == 0) return 0;
	return a * (b / a) + f(b % a, a);
}

signed main() {
	int n, x;
	cin >> n >> x;
	cout << f(n - x, x) * 3 << endl;
	return 0;
}