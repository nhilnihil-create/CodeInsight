#include <iostream>
using namespace std;

const int N = 505, D = 3900;

int a[N][N];
int main() {
	int n, m, w, h;
	cin >> n >> m >> w >> h;
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % w == 0 && j % h == 0) {
				a[i][j] = -D * (w * h - 1) - 1;
			}
			else {
				a[i][j] = D;
			}
			s += a[i][j];
		}
	}
	if (s <= 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
