#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;
int main()
{
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	string ans = "";
	rep(i, ty - sy)	ans += 'U';
	rep(i, tx - sx)	ans += 'R';
	rep(i, ty - sy)	ans += 'D';
	rep(i, tx - sx)	ans += 'L';
	ans += 'L';
	rep(i, ty - sy + 1)	ans += 'U';
	rep(i, tx - sx + 1)	ans += 'R';
	ans += 'D';
	ans += 'R';
	rep(i, ty - sy + 1)	ans += 'D';
	rep(i, tx - sx + 1)	ans += 'L';
	ans += 'U';
	cout << ans << endl;
	return 0;
}