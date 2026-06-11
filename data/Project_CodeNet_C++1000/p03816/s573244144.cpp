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
	int64 nn, tmp, ans;
	cin >> nn;
	set<int64> aa;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> tmp;
		aa.insert(tmp);
	}
	ans = aa.size();
	if(ans % 2 == 0)
	{
		ans--;
	}
	cout << ans << endl;
	return 0;
}
