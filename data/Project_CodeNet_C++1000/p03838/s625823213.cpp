#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int ans = 2100000000;
	if (x < y) ans = y-x;
	if (-x <= y) ans = min(ans, 1 + y + x);
	if (x <= -y) ans = min(ans, 1 - y - x);
	if (x > y) ans = min(ans, 2 - y + x);
	cout << ans << endl;
}
