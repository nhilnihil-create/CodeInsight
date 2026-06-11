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

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 xx, ans = 0;
	cin >> xx;
	ans = xx / 11;
	ans *= 2;
	xx %= 11;
	if(xx == 0)
	{
		0;
	}
	else if(xx <= 6)
	{
		ans++;
	}
	else
	{
		ans += 2;
	}
	cout << ans;
	return 0;
}
