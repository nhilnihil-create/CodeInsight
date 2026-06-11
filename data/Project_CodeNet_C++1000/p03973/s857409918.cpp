#include <iostream>
using namespace std;
int n, a, cur; long long ret;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a >= cur + 2) ret += (a - 1) / (cur + 1);
		if (cur == 0 || a == cur + 1) cur++;
	}
	cout << ret << "\n";
	return 0;
}