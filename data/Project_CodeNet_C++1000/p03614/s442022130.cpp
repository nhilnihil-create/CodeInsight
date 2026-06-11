#include <iostream>
using namespace std;
int n, p[100010], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> p[i];
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) {
			ans++;
			if (p[i + 1] == i + 1)i++;
		}
	}
	cout << ans << endl;
	return 0;
}