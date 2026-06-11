#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int n0=0, n1=0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a&1) n1++;
		else n0++;
	}
	long long x0 = pow(2, n0);
	long long x1;
	if (n1 >= 1) x1 = pow(2, n1-1);
	else if (p == 0) x1 = 1;
	else x1 = 0;
	long long ans = x0 * x1;
	cout << ans << endl;
	return 0;
}