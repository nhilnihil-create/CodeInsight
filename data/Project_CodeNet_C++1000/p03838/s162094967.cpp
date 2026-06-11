#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int x, y; cin >> x >> y;
	int ans = 2 * 1e9;
	if (x < y) ans = min(ans, y - x);
	if (-x <= y) ans = min(ans, y + x + 1);
	if (x <= -y) ans = min(ans, -y - x + 1);
	if (-x <= -y) ans = min(ans, -y + x + 2);
	cout << ans << endl;
}