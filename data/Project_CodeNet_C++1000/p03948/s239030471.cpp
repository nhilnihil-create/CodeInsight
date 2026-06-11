#include <iostream>
using namespace std;

int main()
{
	int n, mx = -1, mn = 1e9, cnt = 0, x, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (mn > x) {
			mn = x;
		} else {
			if (x - mn > mx) {
				mx = x - mn;
				cnt = 0;
			}
			if (mx == x - mn) ++cnt;
		}
	}
	cout << cnt << '\n';
}
