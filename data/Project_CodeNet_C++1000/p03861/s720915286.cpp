#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 aa, bb, xx, ans;
	cin >> aa >> bb >> xx;
	ans = bb / xx + 1;
	ans -= (aa == 0 ? 0 : (aa - 1) / xx + 1);
	cout << ans << endl;
	return 0;
}