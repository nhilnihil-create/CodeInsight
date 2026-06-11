#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	unsigned long long a, b;
	cin >> n >> a >> b;
	int from;
	cin >> from;
    unsigned long long ans = 0;
	for (int i = 1; i < n; i++) {
		int to;
		cin >> to;
		if (a * (to - from) < b) {
			ans += a * (to - from);
		}
		else {
			ans += b;
		}
		from = to;
	}
	cout << ans << endl;
}