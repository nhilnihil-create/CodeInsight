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
	int64 nn, xx, ans = 0;
	cin >> nn >> xx;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	if(aa[0] > xx)
	{
		ans += aa[0] - xx;
		aa[0] = xx;
	}
	for(int64 ii = 1;ii < nn;ii++)
	{
		if(aa[ii - 1] + aa[ii] > xx)
		{
			ans += aa[ii] + aa[ii - 1] - xx;
			aa[ii] = xx - aa[ii - 1];
		}
	}
	cout << ans << endl;
	return 0;
}