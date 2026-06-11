#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int main() {
	int n, mini = N, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mini = min(mini, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == mini) {
			x++;
		}
		if (a[i] == mini + 1) {
			y++;
		}
		if (a[i] != mini && a[i] != mini + 1) {
			cout << "No";
			return 0;
			
		}
	}
	if (y == 0) {
		if (mini == n - 1 || mini * 2 <= n) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}
	else {
		if ((mini + 1 - x) * 2 <= n - x && (mini + 1 - x) > 0) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}
	return 0;
}
