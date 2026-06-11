#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int n;

int a[2 * N];
bool b[2 * N];
bool isval(int x) {
	for (int i = 1; i < 2 * n; i++) {
		b[i] = (a[i] >= x);
	}
	for (int i = 1; i < n; i++) {
		if (b[n + i] == b[n + i - 1]) {
			return b[n + i];
		}
		if (b[n - i] == b[n - i + 1]) {
			return b[n - i];
		}
	}
	if (n % 2)
		return b[n];
	else
		return !b[n];
}
int main() {
	cin >> n;
	for (int i = 1; i < 2 * n; i++) {
		cin >> a[i];
	}
	int dw = 1, up = 2 * n;
	while (up - dw > 1) {
		int md = (dw + up) / 2;
		if (isval(md))
			dw = md;
		else
			up = md;
	}
	cout << dw << endl;
	return 0;
}
