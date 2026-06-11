#include <iostream>
using namespace std;

int n, x;
long long ans, cnt = 1;

int main() {
	cin >> n;

	cin >> x;
	ans += (x - 1);

	for (int i = 1; i < n; i++) {
		cin >> x;
                if (x > (cnt + 1))
                        ans += ((x - 1) / (cnt + 1));
		else if (x == (cnt + 1))
			++cnt;
	}

	cout << ans << '\n';
	return 0;
}