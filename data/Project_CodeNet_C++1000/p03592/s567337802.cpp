#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	bool ans = false;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
		if (i * (m-j) + j * (n-i) == k) {ans = true; break;}
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}