#include <bits/stdc++.h>
#define INF 2001001001
using namespace std;
int f(int x) {
	if (x < 0)
		return INF;
	else
		return x;
}
int main() {
	int x, y;
	cin >> x >> y;
	int ans = INF;
	ans = min(ans, f(y - x));
	ans = min(ans, f(y - (-x) + 1));
	ans = min(ans, f(-y - x + 1));
	ans = min(ans, f(-y - (-x) + 2));
	ans = min(ans, f(y - (-x) + 1));
	cout << ans << endl;
	return 0;
}