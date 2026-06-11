#include"bits/stdc++.h"
using namespace std;

long long reflect(long long a, long long b) {
	if (a % b == 0) {
		return ((a / b) * 2 - 1)*b;
	}
	else {
		return reflect(b, a % b) + ((a / b) * 2) * b;
	}

}

int main() {
	long long n, x;
	cin >> n >> x;
	if (n - x >= x) {
		cout << n + reflect(n - x, x) << endl;
	}
	else {
		cout << n + reflect(x, n - x) << endl;
	}
	return 0;
}
