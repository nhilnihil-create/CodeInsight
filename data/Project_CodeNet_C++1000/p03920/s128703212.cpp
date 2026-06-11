#include <iostream>
using namespace std;

constexpr int f(int x) {
	return x*(x + 1) / 2;
}

int main()
{
	int n; cin >> n;

	int i = 1;
	for (; i <= n; i++) {
		if (f(i - 1) < n && n <= f(i)) {
			break;
		}
	}

	int m = f(i) - n;
	for (int k = 1; k <= i; k++) {
		if (k != m) {
			cout << k << endl;
		}
	}

	return 0;

}