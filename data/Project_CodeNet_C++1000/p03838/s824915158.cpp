//最初と最後しかボタンBを押さなくていいのでは？ -> 難しい条件分岐をせずとも、4パターン試せばよさそう。
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int x, y;

int calc(int x, int y) {
	if (x > y) return 1e+18;
	return y - x;
}

signed main() {
	cin >> x >> y;
	int res1 = calc(x, y);
	int res2 = calc(x, -y) + 1;
	int res3 = calc(-x, y) + 1;
	int res4 = calc(-x, -y) + 2;
	cout << min({res1, res2, res3, res4}) << endl;
	return 0;
}