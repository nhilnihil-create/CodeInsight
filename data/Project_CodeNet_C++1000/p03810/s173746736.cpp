#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int n;

int a[N];


int bmm(int x, int y) {
	if (y == 0) {
		return x;
	}
	return bmm(y, x % y);
}

int solve() {
	//cout << "75 " << endl;
	int c = 0;
	long long s = 0;
	bool b = false;
	for (int i = 0; i < n; i++) {
		s += a[i];
		c += a[i] % 2;
		if (a[i] == 1) {
			b = true;
		}

	}
	if (n == 1) {
		if (a[0] == 1) {
			return 2;
		}
		else {
			return 1;
		}
	}
	if (s % 2 != n % 2) {
		return 1;
	}
	else {
		if (b || c != 1) {
			return 2;
		}
		else {
			int x = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] % 2)
					a[i]--;
				x = bmm(x, a[i]);
			}
			for (int i = 0; i < n; i++) {
				a[i] /= x;
			}
			return 3 - solve();
		}
	}

}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = solve();
	if (ans == 1) {
		cout << "First";
	}
	else {
		cout << "Second";
	}


}
